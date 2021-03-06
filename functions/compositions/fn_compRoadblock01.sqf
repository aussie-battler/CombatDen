/*
    Copyright (C) 2019 D. Ottavio

    This program is free software: you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not, see
    <https://www.gnu.org/licenses/>.

    Description:

    Spawn a roadblock composition.

    Parameter(s):

    0: ARRAY - Position

    1: NUMBER - Direction

    2: STRING - Faction name.  If this is provided,
    a flag will be placed at the roadblock.

    Returns: true
*/
#include "..\..\macros.hpp"

params [
    ["_pos", [], [[]], [2,3]],
    ["_dir", 0,  [0]],
    ["_faction", "", [""]]
];

if (_pos isEqualTo []) exitWith {
     ERROR("pos parameter cannot be empty");
     false;
};
if (_faction == "") exitWith {
    ERROR("faction parameter cannot be empty");
    false;
};

private _climate = DEN_CLIMATE;
private _era     = DEN_ERA(_faction);
private _objs    = [];

if (_era >= ERA_MODERN) then {
    private _bunkerTower = "Land_BagBunker_Tower_F";

    if (_climate == "Tropic" || _climate == "Wood") then {
        _bunkerTower = "Land_HBarrier_01_tower_green_F";
    };

    _objs = [
        ["Land_CncBarrier_F",[-4.10803,-0.330566,0],181.108,1,0,[],"","",true,false],
        ["RoadBarrier_F",[-4.39307,-2.39038,-0.00399923],177.317,1,0.0159713,[],"","",true,false],
        ["FlagPole_F",[-5.43176,0.761475,0],0,1,0,[],"","",true,false],
        ["Land_CncBarrier_F",[-6.74866,-0.289551,0],181.326,1,0,[],"","",true,false],
        ["Land_CncBarrier_F",[6.78259,-0.836426,0],181.409,1,0,[],"","",true,false],
        ["RoadBarrier_F",[7.01086,-2.70459,-0.00399923],184.508,1,0.0168094,[],"","",true,false],
        ["Land_CncBarrier_F",[9.42322,-0.873535,0],181.185,1,0,[],"","",true,false],
        [_bunkerTower,[8.56775,5.39307,0],2.53815,1,0,[],"","",true,false],
        ["Land_CncBarrier_F",[11.7006,-0.0161133,0],138.856,1,0,[],"","",true,false],
        ["Land_CncBarrier_F",[12.7103,2.24658,0],90.833,1,0,[],"","",true,false],
        ["O_HMG_01_high_F",[7.797,4.08789,2.78],186.362,1,0,[],"","",true,false]
    ];
} else {
    private _bunker = "Land_BagBunker_Small_F";
    if (_climate == "Tropic" || _climate == "Wood") then {
        _bunker = "Land_BagBunker_01_small_green_F";
    };

    _objs = [
        [_bunker,[5.77905,1.23389,0],0,1,0,[],"","",true,false],
        [_bunker,[-6.97095,1.23389,0],0,1,0,[],"","",true,false],
        ["FlagPole_F",[-6.07385,5.90063,0],0,1,0,[],"","",true,false]
    ];

    if (_era > ERA_WW2) then {
        _objs pushBack ["Land_CncBarrier_F",[4.78125,-2.20313,0],181.326,1,0,[],"","",true,false];
        _objs pushBack ["Land_CncBarrier_F",[-5.46875,-1.95313,0],181.326,1,0,[],"","",true,false];
        _objs pushBack ["Land_CncBarrier_F",[7.53125,-2.20313,0],181.326,1,0,[],"","",true,false];
        _objs pushBack ["Land_CncBarrier_F",[-8.21875,-1.95313,0],181.326,1,0,[],"","",true,false];
    };
};

[_pos, _dir - 180, _objs] call BIS_fnc_objectsMapper;

private _flagTexture = getText (missionConfigFile >> "CfgFactions" >> _faction >> "flagTexture");
private _flagPole    = nearestObject [_pos, "FlagPole_F"];
_flagPole setFlagTexture _flagTexture;

true;
