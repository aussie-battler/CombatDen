/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Run local host mission logic based on the mission type defined
    by Params.  For MP, this should be run on each host including
    the server.

    Parameter(s):

    0: NUMBER - Mission type defined by "CfgSettings" >> "Mission" >> "Values".
    This value cannot be -1 however.

    1: STRING - enemy zone

    2: OBJECT - Transport helicopter to take players to the zone.

    3: STRING - Enemy faction. See CfgFactions.

    Returns: true
*/
#include "..\..\macros.hpp"

params [
    ["_type",          0,       [0]],
    ["_zone",          "",      [""]],
    ["_helo",          objNull, [objNull]],
    ["_bluforFaction", "",      [""]],
    ["_opforFaction",  "",      [""]],
    ["_arsenal",       objNull, [objNull]]
];

/*
 * If ACE Respawn Gear is not present in MP, then give a respawned
 * player the same gear they had entering the transport vehicle.
 */
private _aceRespawnGear = missionNamespace getVariable ["ace_respawn_savePreDeathGear", false];
if (isMultiPlayer && hasInterface && !_aceRespawnGear) then {
    _helo addEventHandler ["GetIn", {
        params ["", "", "_unit", ""];

        if (local _unit) then {
            _unit setVariable ["den_loadout", (getUnitLoadout _unit)];
        };
    }];

    player addEventHandler ["Respawn", {
        params ["_unit", ""];

        private _loadout = _unit getVariable ["den_loadout", []];
        if !(_loadout isEqualTo []) then {
            _unit setUnitLoadout _loadout;
        };
    }];
};

private _bluforFactionName = getText (missionConfigFile >> "CfgFactions" >> _bluforFaction >> "name");
private _opforFactionName  = getText (missionConfigFile >> "CfgFactions" >> _opforFaction >> "name");

private _success = false;
private _missionArgs = [_zone, _helo, _bluforFactionName , _opforFactionName, _arsenal];
switch (_type) do {
    case 0: {
        _success = _missionArgs call den_fnc_defendLocal;
    };
    case 1: {
        _success = _missionArgs call den_fnc_demoLocal;
    };
    case 2: {
        _success = _missionArgs call den_fnc_campLocal;
    };
    case 3: {
        _success = _missionArgs call den_fnc_chemLocal;
    };
    case 4: {
       _success = _missionArgs call den_fnc_clearLocal;
    };
    case 5: {
        _success = _missionArgs call den_fnc_hostageLocal;
    };
    case 6: {
        _success = _missionArgs call den_fnc_urbanLocal;
    };
    default {
        ERROR("invalid mission type");
    };
};

_success;
