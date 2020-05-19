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
*/

class Csat : Faction
{
    ammoBox     = "Box_East_Ammo_F";
    cargoBox    = "O_CargoNet_01_ammo_F";
    era         = ERA_2034;
    flagTexture = "\A3\Data_F\Flags\Flag_CSAT_CO.paa";
    name        = "CSAT";
    side        = SIDE_OPFOR;

    class Arsenal : Arsenal
    {
        class Base : Base
        {
            grenades[] += {
                "SmokeShellBlue",
                "SmokeShellGreen",
                "SmokeShellOrange",
                "SmokeShellPurple",
                "SmokeShellRed",
                "SmokeShellYellow",
                "SmokeShell",
                "HandGrenade"
            };
            gceGrenades[] += {
                "ACE_M84"
            };
            mags[] = {
                "30Rnd_65x39_caseless_green",
                "30Rnd_65x39_caseless_green_mag_Tracer",
                "150Rnd_762x54_Box",
                "150Rnd_762x54_Box_Tracer",
                "10Rnd_762x54_Mag",
                "150Rnd_93x64_Mag",
                "100Rnd_580x42_Mag_F",
                "100Rnd_580x42_Mag_Tracer_F",
                "30Rnd_580x42_Mag_F",
                "30Rnd_580x42_Mag_Tracer_F",
                "10Rnd_93x64_DMR_05_Mag",
                "30Rnd_556x45_Stanag",
                "Titan_AA",
                "Vorona_HEAT",
                "Vorona_HE",
                "RPG32_F",
                "RPG32_HE_F"
            };
            weapons[] = {
                "arifle_Katiba_F",
                "arifle_Katiba_GL_F",
                "arifle_Katiba_C_F",
                "srifle_DMR_05_blk_F",
                "srifle_DMR_05_hex_F",
                "MMG_01_hex_F",
                "LMG_Zafir_F",
                "srifle_DMR_01_F",
                "srifle_DMR_07_blk_F",
                "arifle_CTAR_blk_F",
                "arifle_CTAR_GL_blk_F",
                "arifle_CTARS_blk_F",
                "arifle_ARX_blk_F"
            };
            launchers[] = {
                "launch_RPG32_F",
                "launch_O_Titan_F",
                "launch_O_Vorona_brown_F"
            };
            aceSights[] = {
                "ace_optic_lrps_2d",
                "ace_optic_lrps_pip",
                "ace_optic_sos_2d",
                "ace_optic_sos_pip",
                "ace_optic_mrco_2d"
            };
            sights[] = {
                "optic_aco_grn",
                "optic_arco_blk_f",
                "optic_holosight_blk_f",
                "optic_mrco",
                "optic_khs_blk",
                "optic_sos",
                "optic_lrps",
                "optic_nightstalker",
                "optic_nvs",
                "optic_dms"
            };
            bipods[] = {
                "bipod_02_f_blk",
                "bipod_02_f_hex"
            };
            attachments[] += {
                "muzzle_snds_H",
                "muzzle_snds_M",
                "muzzle_snds_M"
            };
        };
        class SemiArid : Base
        {
            csatSemiAridWeapons[] = {
                "srifle_DMR_05_tan_f",
                "MMG_01_tan_F",
                "srifle_DMR_07_hex_F",
                "arifle_CTAR_hex_F",
                "arifle_CTAR_GL_hex_F",
                "arifle_CTARS_hex_F",
                "arifle_ARX_hex_F"
            };
            csatSemiAridVests[] = {
                "V_HarnessO_brn",
                "V_HarnessOGL_brn"
            };
            csatSemiAridBacpacks[] = {
                "B_AssaultPack_ocamo",
                "B_Bergen_hex_F",
                "B_Carryall_ocamo",
                "B_FieldPack_ocamo",
                "B_TacticalPack_ocamo",
                "B_ViperHarness_hex_F",
                "B_ViperLightHarness_hex_F",
                "B_FieldPack_cbr"
            };
            csatSemiAridHelmets[] = {
                "H_HelmetO_ocamo",

            };
            csatSemiAridUniforms[] = {
                "U_O_CombatUniform_ocamo"
            };
            csatSemiAridFaceware[] = {
                "G_Bandanna_tan",
                "G_Bandanna_khk"
            };
        };
        class Tropic : Base
        {
            csatTropicSights[] = {
                "optic_dms_ghex_f",
                "optic_arco_ghex_f"
            };
            csatTropicWeapons[] = {
                "srifle_DMR_07_ghex_F",
                "arifle_CTAR_ghex_F",
                "arifle_CTAR_GL_ghex_F",
                "arifle_CTARS_ghex_F",
                "arifle_ARX_ghex_F"
            };
            csatTropicLaunchers[] = {
               "launch_RPG32_ghex_F",
               "launch_O_Titan_ghex_F",
               "launch_O_Vorona_green_F"
            };
            csatTropicVests[] = {
                "V_HarnessO_ghex_F"
            };
            csatTropicBackpacks[] = {
                "B_FieldPack_ghex_F"
            };
        };

        class Arid   : SemiArid {};
        class Wood   : Tropic {};
        class Winter : Wood {};
    };

    class Vehicle
    {
        class SemiArid
        {
            heloTransport      = "O_Heli_Light_02_unarmed_F";
            heloTransportLarge = "O_Heli_Transport_04_covered_F";
            heloCargo          = "O_Heli_Transport_04_box_F";
            truckAssault       = "O_MRAP_02_hmg_F";
            truckSupplyAmmo    = "O_Truck_03_ammo_F";
            truckSupplyCargo   = "O_Truck_03_repair_F";
            truckSupplyFuel    = "O_Truck_03_fuel_F";
        };
        class Arid   : SemiArid {};
        class Tropic : SemiArid
        {
            truckAssault     = "O_T_MRAP_02_hmg_ghex_F";
            truckSupplyAmmo  = "O_T_Truck_03_ammo_ghex_F";
            truckSupplyCargo = "O_T_Truck_03_repair_ghex_F";
            truckSupplyFuel  = "O_T_Truck_03_fuel_ghex_F";
        };
        class Wood : Tropic {};
        class Winter : Wood {};
    };

#define CSAT_NVG  "NVGoggles_OPFOR"

    class Group : Group
    {
        class Couple : Couple {};
        class Single : Single {};
        class Squad  : Squad {};
        class Team   : Team {};
        class Triple : Triple {};

        class SemiArid
        {
            class TruckCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_crew_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_crew_F";
                };
            };
            class HeloPilot : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_pilot_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_pilot_F";
                };
            };
            class HeloCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_helicrew_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_helicrew_F";
                };
            };
            class Pilot : Single
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_pilot_F";
                };
            };
            class Sentry : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_soldier_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_soldier_F";
                };
            };
            class FireTeam : Team
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_soldier_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_soldier_AR_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_soldier_LAT_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_soldier_F";
                };
            };
            class AssaultSquad : Squad
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_Soldier_SL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_Soldier_AR_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_Soldier_AR_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_Soldier_AAR_F";
                };
                class Unit4 : Unit4
                {
                    vehicle = "O_soldier_M_F";
                };
                class Unit5 : Unit5
                {
                    vehicle = "O_Sharpshooter_F";
                };
                class Unit6 : Unit6
                {
                    vehicle = "O_Soldier_LAT_F";
                };
                class Unit7 : Unit7
                {
                    vehicle = "O_medic_F";
                };
            };
            class ReconSquad : Squad
            {
                nvg = CSAT_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "O_recon_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_recon_M_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_recon_medic_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_recon_F";
                };
                class Unit4 : Unit4
                {
                    vehicle = "O_recon_LAT_F";
                };
                class Unit5 : Unit5
                {
                    vehicle = "O_recon_JTAC_F";
                };
                class Unit6 : Unit6
                {
                    vehicle = "O_recon_exp_F";
                };
                class Unit7 : Unit7
                {
                    vehicle = "O_recon_F";
                };
            };
            class ReconTeam : Team
            {
                nvg = CSAT_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "O_recon_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_recon_M_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_recon_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_recon_F";
                };
            };
            class MotorizedHmg : Single
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_MRAP_02_hmg_F";
                };
            };
            class MotorizedTeam : Triple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_MRAP_02_hmg_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_soldier_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_soldier_F";
                };
            };
            class MotorizedAssault : AssaultSquad
            {
                type = "motorized";

                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8
                {
                    position[] = {-20,-20,0};
                    rank = "LIEUTENANT";
                    vehicle = "O_MRAP_02_hmg_F";
                };
            };
        };
        class Arid : SemiArid
        {
            class TruckCrew : TruckCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloPilot : HeloPilot
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloCrew  : HeloCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class Pilot : Pilot
            {
                class Unit0 : Unit0 {};
            };
            class Sentry : Sentry
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class FireTeam : FireTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class AssaultSquad : AssaultSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconSquad : ReconSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconTeam : ReconTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class MotorizedHmg : MotorizedHmg
            {
                class Unit0 : Unit0 {};
            };
            class MotorizedTeam : MotorizedTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
            };
            class MotorizedAssault : MotorizedAssault
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8 : Unit8 {};
            };
        };
        class Tropic
        {
            class TruckCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_T_crew_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_crew_F";
                };
            };
            class HeloPilot : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_T_pilot_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_pilot_F";
                };
            };
            class HeloCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_T_helicrew_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_helicrew_F";
                };
            };
            class Pilot : Single
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_T_pilot_F";
                };
            };
            class Sentry : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_T_Soldier_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_Soldier_F";
                };
            };
            class FireTeam : Team
            {
                class Unit0 : Unit0
                {
                     vehicle = "O_T_Soldier_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_Soldier_AR_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_T_Soldier_LAT_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_T_Soldier_F";
                };
            };
            class AssaultSquad : Squad
            {
                class Unit0 : Unit0
                {
                    vehicle = "O_T_Soldier_SL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_Soldier_AR_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_T_Soldier_AR_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_T_Soldier_AAR_F";
                };
                class Unit4 : Unit4
                {
                    vehicle = "O_T_Soldier_M_F";
                };
                class Unit5 : Unit5
                {
                    vehicle = "O_T_Soldier_GL_F";
                };
                class Unit6 : Unit6
                {
                    vehicle = "O_T_Soldier_LAT_F";
                };
                class Unit7 : Unit7
                {
                    vehicle = "O_T_Medic_F";
                };
            };
            class ReconSquad : Squad
            {
                nvg = CSAT_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "O_T_Recon_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_Recon_M_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_T_Recon_medic_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_T_Recon_F";
                };
                class Unit4 : Unit4
                {
                    vehicle = "O_T_Recon_LAT_F";
                };
                class Unit5 : Unit5
                {
                    vehicle = "O_T_Recon_JTAC_F";
                };
                class Unit6 : Unit6
                {
                    vehicle = "O_T_Recon_exp_F";
                };
                class Unit7 : Unit7
                {
                    vehicle = "O_T_Recon_F";
                };
            };
            class ReconTeam : Team
            {
                nvg = CSAT_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "O_T_Recon_TL_F";
                };
                class Unit1 : Unit1
                {
                    vehicle = "O_T_Recon_M_F";
                };
                class Unit2 : Unit2
                {
                    vehicle = "O_T_Recon_F";
                };
                class Unit3 : Unit3
                {
                    vehicle = "O_T_Recon_F";
                };
            };
            class MotorizedHmg : Single
            {
                class Unit0 : Unit0
                {
                     vehicle = "O_T_MRAP_02_hmg_ghex_F";
                };
            };
            class MotorizedTeam : Triple
            {
                class Unit0 : Unit0
                {
                     vehicle = "O_T_MRAP_02_hmg_ghex_F";
                };
                class Unit1 : Unit1
                {
                     vehicle = "O_T_Soldier_F";
                };
                class Unit2 : Unit2
                {
                     vehicle = "O_T_Soldier_F";
                };
            };
            class MotorizedAssault : AssaultSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8
                {
                    position[] = {-20,-20,0};
                    rank = "LIEUTENANT";
                    vehicle = "O_T_MRAP_02_hmg_ghex_F";
                };
            };
        };
        class Wood : Tropic
        {
            class TruckCrew : TruckCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloPilot : HeloPilot
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloCrew  : HeloCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class Pilot : Pilot
            {
                class Unit0 : Unit0 {};
            };
            class Sentry : Sentry
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class FireTeam : FireTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class AssaultSquad : AssaultSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconSquad : ReconSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconTeam : ReconTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class MotorizedHmg : MotorizedHmg
            {
                class Unit0 : Unit0 {};
            };
            class MotorizedTeam : MotorizedTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
            };
            class MotorizedAssault : MotorizedAssault
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8 : Unit8 {};
            };
        };
        class Winter : Wood
        {
            class TruckCrew : TruckCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloPilot : HeloPilot
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloCrew  : HeloCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class Pilot : Pilot
            {
                class Unit0 : Unit0 {};
            };
            class Sentry : Sentry
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class FireTeam : FireTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class AssaultSquad : AssaultSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconSquad : ReconSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconTeam : ReconTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class MotorizedHmg : MotorizedHmg
            {
                class Unit0 : Unit0 {};
            };
            class MotorizedTeam : MotorizedTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
            };
            class MotorizedAssault : MotorizedAssault
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8 : Unit8 {};
            };
        };
    };

#define CSAT_AT_MAG_COUNT              11
#define CSAT_AUTORIFLE_NG_MAG_COUNT     4
#define CSAT_AUTORIFLE_QBZ_MAG_COUNT    6
#define CSAT_GRENADIRE_MAG_COUNT       11
#define CSAT_MARKSMAN_MAG_COUNT        11
#define CSAT_MEDIC_MAG_COUNT           11
#define CSAT_RIFLEMAN_MAG_COUNT        11

    class Loadout : Loadout
    {
        class Base : Base
        {
            aceNvg        = "ACE_NVG_Wide";
            aceBinoculars = "ACE_Vector";

            handgun    = "hgun_Rook40_F";
            headgear   = "H_HelmetO_ocamo";
            rifleSight = "optic_mrco";
            nvg        = "NVGoggles_OPFOR";
            rifleLight = "acc_flashlight";

            class Uniform : Uniform
            {
                type = "U_O_CombatUniform_ocamo";

                csatItems[] = {
                    "16Rnd_9x21_Mag",
                    "16Rnd_9x21_Mag"
                };
            };
            class Vest : Vest
            {
                type = "V_HarnessO_brn";
            };
            class Backpack : Backpack
            {
                type = "B_FieldPack_ocamo";
            };
            class LinkedItems : LinkedItems {};
        };
        class RiflemanBase : Base
        {
            unit            = "O_Soldier_F";
            primaryMagCount = CSAT_RIFLEMAN_MAG_COUNT;

            class Uniform : Uniform {};

            class Vest : Vest
            {
               riflemanBaseItems[] = {
                    "HandGrenade",
                    "HandGrenade",
                    "SmokeShell",
                    "SmokeShell"
                };
            };
            class Backpack : Backpack
            {
                riflemanBaseItems[] = {
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade",
                };
            };
            class LinkedItems : LinkedItems {};
        };
        class GrenadierBase : RiflemanBase
        {
            unit              = "O_Soldier_GL_F";
            primaryMagCount   = CSAT_GRENADIRE_MAG_COUNT;
            secondaryMag      = "1Rnd_HE_Grenade_shell";
            secondaryMagCount = 14;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
               grenadierBaseItems[] = {
                    "1Rnd_Smoke_Grenade_shell"
               };
            };
            class Backpack    : Backpack {};
            class LinkedItems : LinkedItems {};
        };
        class AutorifleBase : Base
        {
            unit = "O_Soldier_AR_F";

            class Uniform  : Uniform {};
            class Vest     : Vest {};
            class Backpack : Backpack
            {
                arBaseItems[] = {
                   "HandGrenade",
                   "HandGrenade",
                   "HandGrenade",
                   "HandGrenade",
                   "SmokeShell",
                   "SmokeShell"
                };
            };
            class LinkedItems : LinkedItems {};
        };
        class MarksmanBase : Base
        {
            unit            = "O_soldier_M_F";
            primaryMagCount = CSAT_MARKSMAN_MAG_COUNT ;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
               marksmanBaseItems[] = {
                  "HandGrenade",
                  "HandGrenade",
                  "SmokeShell",
                  "SmokeShell"
               };
            };
            class Backpack : MarksmanBackpack
            {
                type = "B_FieldPack_ocamo";

                marksmanBaseItems[] = {
                  "optic_mrco"
                };
            };
            class LinkedItems : LinkedItems {};
        };
        class MedicBase : Base
        {
            unit            = "O_medic_F";
            primaryMagCount = CSAT_MEDIC_MAG_COUNT;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
                medicBaseItems[] = {
                    "SmokeShell",
                    "SmokeShell",
                    "SmokeShell",
                    "SmokeShell",
                    "SmokeShell",
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade"
                };
            };
            class Backpack    : MedicBackpack
            {
                type = "B_FieldPack_ocamo";
            };
            class LinkedItems : LinkedItems {};
        };
        class AtBase : Base
        {
            unit            = "O_Soldier_LAT_F";
            rifle           = "arifle_Katiba_F";
            primaryMag      = "30Rnd_65x39_caseless_green";
            primaryMagCount = CSAT_AT_MAG_COUNT;

            class Uniform : Uniform {};

            class Vest : Vest
            {
               atBaseItems[] = {
                   "HandGrenade",
                   "HandGrenade",
                   "SmokeShell"
               };
            };
            class Backpack    : Backpack {};
            class LinkedItems : LinkedItems {};
        };
        class EodBase : Base
        {
            unit            = "O_soldier_exp_F";
            primaryMagCount = CSAT_RIFLEMAN_MAG_COUNT;

            class Uniform : Uniform {};

            class Vest : Vest
            {
               eodBaseList[] = {
                    "HandGrenade",
                    "HandGrenade",
                    "SmokeShell",
                    "SmokeShell"
                };
            };
            class Backpack : EodBackpack
            {
                type = "B_TacticalPack_ocamo";
            };
            class LinkedItems : LinkedItems {};
        };
        class EngineerBase : RiflemanBase
        {
            unit            = "O_engineer_F";
            primaryMagCount = CSAT_RIFLEMAN_MAG_COUNT;

            class Uniform  : Uniform {};
            class Vest     : Vest {};

            class Backpack : Backpack
            {
                type = "B_FieldPack_ocamo";

                items[] += {
                    "ToolKit"
                };
            };
            class LinkedItems : LinkedItems {};
        };
        class SemiArid
        {
            class Rifleman
            {
                role = "Rifleman";

                class Kh2002 : RiflemanBase
                {
                    default    = 1;
                    aceType    = "KH2002";
                    type       = "Katiba";
                    rifle      = "arifle_Katiba_F";
                    primaryMag = "30Rnd_65x39_caseless_green";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
                class Qbz : RiflemanBase
                {
                    default    = 1;
                    aceType    = "QBZ-95-1";
                    type       = "CAR-95";
                    rifle      = "arifle_CTAR_blk_F";
                    primaryMag = "30Rnd_580x42_Mag_F";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
            };
            class Grenadier
            {
                role = "Grenadier";

                class Kh2002 : GrenadierBase
                {
                    default    = 1;
                    aceType    = "KH2002 GL";
                    type       = "Katiba GL";
                    rifle      = "arifle_Katiba_GL_F";
                    primaryMag = "30Rnd_65x39_caseless_green";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
                class Qbz: GrenadierBase
                {
                    aceType    = "QBZ-95-1 GL";
                    type       = "CAR-95 GL";
                    rifle      = "arifle_CTAR_GL_blk_F";
                    primaryMag = "30Rnd_580x42_Mag_F";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
            };
            class SquadLeader : Grenadier
            {
                role = "Squad Leader";

                class Kh2002 : Kh2002
                {
                    unit = "O_Soldier_SL_F";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
                class Qbz : Qbz
                {
                    unit = "O_Soldier_SL_F";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
            };
            class Autorifleman
            {
                role = "Autorifleman";

                class Ng : AutorifleBase
                {
                    default         = 1;
                    aceType         = "NG7";
                    type            = "Zafir";
                    rifle           = "LMG_Zafir_F";
                    primaryMag      = "150Rnd_762x54_Box_Tracer";
                    primaryMagCount = CSAT_AUTORIFLE_NG_MAG_COUNT;

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
                class Qbz : AutorifleBase
                {
                    aceType         = "QBZ-95-1 LSW";
                    type            = "CAR-95-1";
                    rifle           = "arifle_CTARS_blk_F";
                    primaryMag      = "100Rnd_580x42_Mag_Tracer_F";
                    primaryMagCount = CSAT_AUTORIFLE_QBZ_MAG_COUNT;

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
            };
            class Marksman
            {
                role = "Marksman";

                class Vs : MarksmanBase
                {
                    default    = 1;
                    aceType    = "VS 121";
                    type       = "Rahim";
                    rifle      = "srifle_DMR_01_F";
                    rifleBipod = "bipod_02_f_blk";
                    rifleSight = "optic_dms";
                    primaryMag = "10Rnd_762x54_Mag";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
                class Cyrus : MarksmanBase
                {
                    type       = "Cyrus";
                    rifle      = "srifle_DMR_05_blk_F";
                    rifleBipod = "bipod_02_f_blk";
                    rifleSight = "optic_khs_blk";
                    primaryMag = "10Rnd_93x64_DMR_05_Mag";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
                class Type115 : MarksmanBase
                {
                    type       = "Type 115";
                    rifle      = "arifle_ARX_blk_F";
                    rifleBipod = "bipod_01_f_snd";
                    rifleSight = "optic_dms";
                    primaryMag = "10Rnd_762x54_Mag";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
            };
            class Medic
            {
                role = "Medic";

                class Kh2002 : MedicBase
                {
                    default    = 1;
                    aceType    = "KH2002";
                    type       = "Katiba";
                    rifle      = "arifle_Katiba_F";
                    primaryMag = "30Rnd_65x39_caseless_green";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
                class Qbz : MedicBase
                {
                    aceType    = "QBZ-95-1";
                    type       = "CAR-95";
                    rifle      = "arifle_CTAR_blk_F";
                    primaryMag = "30Rnd_580x42_Mag_F";

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
            };
            class At
            {
                role = "Anti-Tank";

                class Rpg : AtBase
                {
                    default           = 1;
                    type              = "RPG-42";
                    launcher          = "launch_RPG32_F";
                    secondaryMag      = "RPG32_F";
                    secondaryMagCount = 2;

                    class Uniform  : Uniform {};
                    class Vest     : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems   : LinkedItems {};
                };
            };
            class Eod
            {
                role = "EOD";

                class Kh2002 : EodBase
                {
                    default    = 1;
                    aceType    = "KH2002";
                    type       = "Katiba";
                    rifle      = "arifle_Katiba_F";
                    primaryMag = "30Rnd_65x39_caseless_green";

                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Qbz : EodBase
                {
                    aceType    = "QBZ-95-1";
                    type       = "CAR-95";
                    rifle      = "arifle_CTAR_blk_F";
                    primaryMag = "30Rnd_580x42_Mag_F";

                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Engineer
            {
                role = "Engineer";

                class Kh2002 : EngineerBase
                {
                    default    = 1;
                    aceType    = "KH2002";
                    type       = "Katiba";
                    rifle      = "arifle_Katiba_F";
                    primaryMag = "30Rnd_65x39_caseless_green";

                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Qbz : EngineerBase
                {
                    aceType    = "QBZ-95-1";
                    type       = "CAR-95";
                    rifle      = "arifle_CTAR_blk_F";
                    primaryMag = "30Rnd_580x42_Mag_F";

                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
        };
        class Arid : SemiArid
        {
            class Rifleman : Rifleman
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class SquadLeader : SquadLeader
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Autorifleman : Autorifleman
            {
                class Ng    : Ng {};
                class Qbz   : Qbz {};
            };
            class Grenadier : Grenadier
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Marksman : Marksman
            {
                class Vs      : Vs {};
                class Cyrus   : Cyrus {};
                class Type115 : Type115 {};
            };
            class Medic : Medic
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class At : At
            {
                class Rpg   : Rpg {};
            };
            class Eod : Eod
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Engineer : Engineer
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
        };
        class Tropic : SemiArid
        {
            class Rifleman : Rifleman
            {
                class Kh2002 : Kh2002
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                    class LinkedItems : LinkedItems {};
                };
                class Qbz : Qbz
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class Grenadier : Grenadier
            {
                class Kh2002 : Kh2002
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Qbz : Qbz
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class SquadLeader : SquadLeader
            {
                class Kh2002 : Kh2002
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Qbz : Qbz
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class Autorifleman : Autorifleman
            {
                class Ng : Ng
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Qbz : Qbz
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class Marksman : Marksman
            {
               class Vs : Vs
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Cyrus : Cyrus
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Type115 : Type115
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class Medic : Medic
            {
                class Kh2002 : Kh2002
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Qbz : Qbz
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class At : At
            {
                class Rpg : Rpg
                {
                    headgear = "H_HelmetO_ghex_F";
                    launcher = "launch_RPG32_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class Eod : Eod
            {
                class Kh2002 : Kh2002
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Qbz : Qbz
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
            class Engineer : Engineer
            {
                class Kh2002 : Kh2002
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
                class Qbz : Qbz
                {
                    headgear = "H_HelmetO_ghex_F";

                    class Uniform : Uniform
                    {
                        type = "U_O_T_Soldier_F";
                    };
                    class Vest : Vest
                    {
                        type = "V_HarnessO_ghex_F";
                    };
                    class Backpack : Backpack
                    {
                        type = "B_FieldPack_ghex_F";
                    };
                };
            };
        };
        class Wood : Tropic
        {
            class Rifleman : Rifleman
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class SquadLeader : SquadLeader
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Autorifleman : Autorifleman
            {
                class Ng    : Ng {};
                class Qbz   : Qbz {};
            };
            class Grenadier : Grenadier
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Marksman : Marksman
            {
                class Vs      : Vs {};
                class Cyrus   : Cyrus {};
                class Type115 : Type115 {};
            };
            class Medic : Medic
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class At : At
            {
                class Rpg : Rpg {};
            };
            class Eod : Eod
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Engineer : Engineer
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
        };
        class Winter : Wood
        {
            class Rifleman : Rifleman
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class SquadLeader : SquadLeader
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Autorifleman : Autorifleman
            {
                class Ng    : Ng {};
                class Qbz   : Qbz {};
            };
            class Grenadier : Grenadier
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Marksman : Marksman
            {
                class Vs      : Vs {};
                class Cyrus   : Cyrus {};
                class Type115 : Type115 {};
            };
            class Medic : Medic
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class At : At
            {
                class Rpg : Rpg {};
            };
            class Eod : Eod
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
            class Engineer : Engineer
            {
                class Kh2002 : Kh2002 {};
                class Qbz    : Qbz {};
            };
        };
    };
};
