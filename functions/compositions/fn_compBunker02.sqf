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

    Spawn a pow camp composition.

    Parameter(s):

    0: ARRAY - Position

    0: (Optional) NUMBER - Direction

    Returns: true
*/
#include "..\..\macros.hpp"

params [
    ["_pos", [], [[]], [2,3]],
    ["_dir", 0,  [0]]
];

if (_pos isEqualTo []) exitWith {
     ERROR("pos parameter cannot be empty");
     false;
};

private _bunker = "Land_BagBunker_Small_F";
private _fence  = "Land_BagFence_Long_F";

private _climate = DEN_CLIMATE;
if (_climate == "Tropic" || _climate == "Wood") then {
    _bunker = "Land_BagBunker_01_small_green_F";
    _fence  = "Land_BagFence_01_long_green_F";
};

private _objs = [
	["CamoNet_BLUFOR_open_F",[-0.170898,-0.097168,0],85.6496,1,0,[],"","",true,false],
	[_bunker,[0.439209,3.60327,0],180.687,1,0,[],"","",true,false],
	[_bunker,[0.432373,-4.25757,0],0,1,0,[],"","",true,false],
	[_fence,[-4.58301,-0.206055,-0.000999928],269.95,1,0,[],"","",true,false],
	[_fence,[-4.58301,3.04395,-0.000999928],269.95,1,0,[],"","",true,false],
	[_fence,[5.66699,0.0439453,-0.000999928],269.95,1,0,[],"","",true,false],
	[_fence,[-4.58301,-3.45605,-0.000999928],269.95,1,0,[],"","",true,false],
	[_fence,[5.66699,-3.20605,-0.000999928],269.95,1,0,[],"","",true,false],
	[_fence,[5.66699,3.29395,-0.000999928],269.95,1,0,[],"","",true,false]
];

[_pos, _dir, _objs] call BIS_fnc_objectsMapper;

true;
