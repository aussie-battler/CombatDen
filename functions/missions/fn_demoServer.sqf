/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Mission logic to run only on the server.

    Parameter(s):

    0: GROUP - player group

    1: OBJECT - Transport helicopter to take players to the zone.

    2: STRING - friendly faction. See CfgFactions.

    3: STRING - enemy faction. See CfgFactions.

    4: NUMBER - difficulty. See CfgParams.

    Returns: STRING - zone location name, empty string on error.
*/
#include "..\..\macros.hpp"

params [
    ["_playerGroup",     grpNull, [grpNull]],
    ["_helo",            objNull, [objNull]],
    ["_friendlyFaction", "",      [""]],
    ["_enemyFaction",    "",      [""]],
    ["_difficulty",      0,       [0]]
];

if (isNull _playerGroup) exitWith {
    ERROR("group parameter must not be null");
    "";
};

if (isNull _helo) exitWith {
    ERROR("helo parameter must not be null");
    "";
};

if (_friendlyFaction == "") exitWith {
    ERROR("friendly faction cannot be empty");
    "";
};

if (_enemyFaction == "") exitWith {
    ERROR("enemy faction cannot be empty");
    "";
};
/*
 * max radius for AO objects
 */
private _zoneRadius   = 250;
private _minLz        = _zoneRadius + 400;
private _maxLz        = _zoneRadius + 450;
private _minReinforce = _minLz;
private _maxReinforce = _maxLz;
private _minPatrol    = 1;
private _maxPatrol    = _zoneRadius;

private _safePosParams = [
    [_minLz,        _maxLz,        15, 0.1], // lz safe position
    [_minReinforce, _maxReinforce, 15, 0.1], // reinforce safe position
    [_minPatrol,    _maxPatrol,    4,  -1]   // patrol safe position
];

private _enemySideStr = getText(missionConfigFile >> "CfgFactions" >> _enemyFaction >> "side");
private _enemyColor   = getText(missionConfigFile >> "CfgMarkers"  >> _enemySideStr >> "color");

private _zone = [
    ["NameVillage", "CityCenter"],
    _zoneRadius,
    _safePosParams,
    _enemyColor
] call den_fnc_zone;

if (_zone isEqualTo []) exitWith {
    ERROR("zone failure");
    "";
};

private _zoneName        = _zone select 0;
private _zoneArea        = _zone select 1;
private _zonePos         = _zoneArea select 0;
private _zoneRadius      = _zoneArea select 1;
private _zoneSafePosList = _zone select 2;
private _lzPos           = _zoneSafePosList select 0;
private _reinforcePos    = _zoneSafePosList select 1;
private _patrolPos       = _zoneSafePosList select 2;

/*
 * lz
 */
[_lzPos, _playerGroup, _helo, _zoneArea, _friendlyFaction] call den_fnc_insert;
[_lzPos, _playerGroup, _friendlyFaction, "den_ordnancesDestroyed", _zoneArea] call den_fnc_extract;

/*
 * ammo crates and enemy units
 */
private _enemySide = [_enemyFaction] call den_fnc_factionSide;
createGuardedPoint [_enemySide, _zonePos, -1, objNull];

private _ammoCrate = getText (missionConfigFile >> "CfgFactions" >> _enemyFaction >> "ammoBox");
if (_ammoCrate == "") then {
    _ammoCrate = "Box_NATO_Ammo_F";
    WARNING_1("missing ammoBox property for faction %1", _enemyFaction);
};

den_crateCount = 0;
den_crateDestroyCount = 0;

private _maxCrates      = 10;
private _maxGuardGroups = 6;
private _patrolType     = "FireTeam";
private _reinforceArgs  = [[_reinforcePos, "MotorizedTeam"]];
private _extractGroup   = "FireTeam";

switch (_difficulty) do {
    case 1: {
        _maxGuardGroups = 8;
        _patrolType = "AssaultSquad";
        _reinforceArgs  = [[_reinforcePos, "MotorizedAssault"]];
    };
    case 2: {
        _maxGuardGroups = 12;
        _patrolType = "AssaultSquad";
        _reinforceArgs  = [
            [_reinforcePos, "MotorizedAssault"],
            [_reinforcePos, "MotorizedAssault"]
        ];
    };
};

private _patrolGroup = [_patrolPos, _enemyFaction, _patrolType] call den_fnc_spawnGroup;
[
    _patrolGroup,
    _zonePos,
    _zoneRadius,
    5,
    "MOVE",
    "AWARE",
    "YELLOW",
    "LIMITED",
    "STAG COLUMN"
] call CBA_fnc_taskPatrol;

private _buildingList = nearestObjects [_zonePos, ["House"], _zoneRadius];
if (_buildingList isEqualTo []) exitWith {
    ERROR_1("building list is empty in %1", _zoneName);
    "";
};
_buildingList call BIS_fnc_arrayShuffle;

// for debugging
den_crates = [];

private _guardUnits     = [];
private _cratePositions = [];

private _guardGroupCount = 0;
{
    private _building = _x;
    private _cratePos = [0,0];
    private _guardPos = [0,0];
    private _posList  = _building buildingPos -1;

    if ((count _posList) > 1) then {
        _guardPos = _posList select 0;
        _cratePos = _posList select 1;
    } else {
        _guardPos = [_building, 5, 10, 1, 0, 0.1, 0, [], [[0,0],[0,0]]] call BIS_fnc_findSafePos;

        // Try to find a position off the road.
        private _roadRetry = 10;
        while {_roadRetry > 0} do {
            _cratePos = [_building, 5, 10, 1, 0, 0.1, 0, [], [[0,0],[0,0]]] call BIS_fnc_findSafePos;
            if ((_cratePos isEqualTo [0,0]) || !(isOnRoad _cratePos)) exitWith{};
            _roadRetry = _roadRetry - 1;
        };
    };

    if !(_cratePos isEqualTo [0,0]) then {
        private _crate = _ammoCrate createVehicle _cratePos;
        _crate addEventHandler ["killed", {
            den_crateDestroyCount = den_crateDestroyCount + 1;
            if ((isNil "den_ordnancesDestroyed") && (den_crateDestroyCount == den_crateCount)) then {
                ["den_ordnancesDestroyed"] call den_fnc_publicBool;
            };
        }];
        den_crateCount = den_crateCount + 1;
        den_crates pushBack _crate;
        _cratePositions pushBack (getPos _crate);
    };

    if ((_guardGroupCount < _maxGuardGroups) && !(_guardPos isEqualTo [0,0])) then {
        private _group = [_guardPos, _enemyFaction, "Sentry"] call den_fnc_spawnGroup;

        private _wp = [
            _group,
            _guardPos,
            0,
            "SCRIPTED",
            "AWARE",
            "YELLOW",
            "FULL",
            "WEDGE"
        ] call CBA_fnc_addWaypoint;

        _wp setWaypointScript "\x\cba\addons\ai\fnc_waypointGarrison.sqf";

        {
            _guardUnits pushBack _x;
        } forEach units _group;

        _guardGroupCount = _guardGroupCount + 1;
    };

    if (den_crateCount == _maxCrates) exitWith {};
} forEach _buildingList;

[_guardUnits, _cratePositions, _enemyFaction] call den_fnc_intelPositions;

[_zoneArea, _reinforceArgs, _enemyFaction, _friendlyFaction] call den_fnc_wave;

// extraction attack
[_reinforcePos, _lzPos, _enemyFaction, _extractGroup] call den_fnc_attackExtraction;

/*
 * Players must have in their possession explosives
 * to advance to the next task
 */
[_playerGroup, _helo] spawn {
    params ["_playerGroup", "_helo"];
    /*
     * Scan player equipment until explosives are found.
     */
    _helo lock true;

    private _explosiveTypes = ["DemoCharge_Remote_Mag", "SatchelCharge_Remote_Mag", "ACE_M14"];
    private _hasExplosive   = false;

    while {!_hasExplosive} do {
        {
            {
                if (_x in _explosiveTypes) exitWith {
                    _hasExplosive = true;
                };
            } forEach (uniformItems _x) + (vestItems _x) + (backpackItems _x);

            if (_hasExplosive) exitWith{};
        } forEach units _playerGroup;

        sleep 2;
    };

    _helo lock false;
    ["den_ordnancePacked"] call den_fnc_publicBool;
};

/*
 * enemy markers
 */
private _infMarkerPos = _zonePos getPos [25, (_zonePos getDir _lzPos)];
private _marker = createMarker ["enemyInfMarker", _infMarkerPos];
_marker setMarkerType (getText(missionConfigFile >> "CfgMarkers" >> _enemySideStr >> "infantry"));
_marker setMarkerColor _enemyColor;

_zoneName;
