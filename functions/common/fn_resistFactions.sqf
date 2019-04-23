/*
    Copyright (C) 2019 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Return the names of the resistance factions.  This is determined
    based on addon configuration.

    Returns: ARRAY - resistance faction names
*/

private _addons = [];

/*
 * ProjectOpfor
 */
if (isClass (configfile >> "CfgPatches" >> "lop_faction_afr")) then {
    _addons pushBack "LopGuerrilla";
};
if (isClass (configfile >> "CfgVehicles" >> "LOP_IRA_Infantry_base")) then {
    _addons pushBack "LopInsurgent";
};
if (isClass (configfile >> "CfgPatches" >> "lop_faction_ists")) then {
    _addons pushBack "LopIsis";
};
if (isClass (configfile >> "CfgPatches" >> "lop_faction_us")) then {
    _addons pushBack "LopNovo";
};
if (isClass (configfile >> "CfgPatches" >> "lop_faction_tka")) then {
    _addons pushBack "LopTakistan";
};
if (isClass (configfile >> "CfgPatches" >> "lop_faction_chdkz")) then {
    _addons pushBack "LopChDkz";
};

/*
 * CFP
 */
if (isClass (configfile >> "CfgPatches" >> "CFP_O_CFRebels")) then {
    _addons pushBack "CfpGuerrilla";
};
if (isClass (configfile >> "CfgPatches" >> "CFP_O_HEZBOLLAH")) then {
    _addons pushBack "CfpHezbollah";
};
if (isClass (configfile >> "CfgPatches" >> "CFP_O_HAMAS")) then {
    _addons pushBack "CfpHamas";
};
if (isClass (configfile >> "CfgPatches" >> "CFP_O_IS")) then {
    _addons pushBack "CfpIsis";
};
if (isClass (configfile >> "CfgPatches" >> "CFP_O_ALQAEDA")) then {
    _addons pushBack "CfpAlQaeda";
};
if (isClass (configfile >> "CfgPatches" >> "CFP_O_BOKOHARAM")) then {
    _addons pushBack "CfpBokoHaram";
};
if (isClass (configfile >> "CfgPatches" >> "CFP_O_ALSHABAAB")) then {
    _addons pushBack "CfpAlShabaab";
};


if (_addons isEqualTo []) then {
    _addons = ["Fia", "Syndikat"];
};

private _climate = [] call den_fnc_worldToClimate;

private _query    = format["(configName _x) in %1", _addons];
private _factions = _query configClasses (missionConfigFile >> "CfgFactions" >> _climate);

_factions
