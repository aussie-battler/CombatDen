/*
    Copyright (C) 2019 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike
*/

class CfpAlQaeda : Faction
{
    addon       = "CFP";
    ammoBox     = "CUP_RUBasicAmmunitionBox";
    flagTexture = "x\cfp\addons\flags\others\alqaeda.paa";
    name        = "Al Qaeda";
    side        = SIDE_GUER;

    // Faction not playable yet.
    class Arsenal {};
    class Vehicle {};
    class Loadout {};

    class Group : Group
    {
        class Couple : Couple {};
        class Single : Single {};
        class Squad  : Squad {};
        class Team   : Team {};
        class Triple : Triple {};

        class SemiArid
        {
            class Sentry : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "CFP_O_ALQAEDA_Rifleman_01";
                };
                class Unit1 : Unit1
                {
                    vehicle = "CFP_O_ALQAEDA_Rifleman_01";
                };
            };
            class FireTeam : Team
            {
                class Unit0 : Unit0
                {
                    vehicle = "CFP_O_ALQAEDA_Team_Leader_01";
                };
                class Unit1 : Unit1
                {
                    vehicle = "CFP_O_ALQAEDA_Machine_Gunner_01";
                };
                class Unit2 : Unit2
                {
                    vehicle = "CFP_O_ALQAEDA_Grenadier_01";
                };
                class Unit3 : Unit3
                {
                    vehicle = "CFP_O_ALQAEDA_Rifleman_AT_01";
                };
            };
            class AssaultSquad : Squad
            {
                class Unit0 : Unit0
                {
                    vehicle = "CFP_O_ALQAEDA_Team_Leader_01";
                };
                class Unit1 : Unit1
                {
                    vehicle = "CFP_O_ALQAEDA_Machine_Gunner_01";
                };
                class Unit2 : Unit2
                {
                    vehicle = "CFP_O_ALQAEDA_Machine_Gunner_01";
                };
                class Unit3 : Unit3
                {
                    vehicle = "CFP_O_ALQAEDA_Grenadier_01";
                };
                class Unit4 : Unit4
                {
                    vehicle = "CFP_O_ALQAEDA_Grenadier_01";
                };
                class Unit5 : Unit5
                {
                    vehicle = "CFP_O_ALQAEDA_Rifleman_AT_01";
                };
                class Unit6 : Unit6
                {
                    vehicle = "CFP_O_ALQAEDA_Rifleman_AT_01";
                };
                class Unit7 : Unit7
                {
                    vehicle = "CFP_O_ALQAEDA_Medic_01";
                };
            };
            class ReconSquad : AssaultSquad
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
            class ReconTeam : FireTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class MotorizedHmg : Single
            {
                class Unit0 : Unit0
                {
                     vehicle = "CFP_O_ALQAEDA_Offroad_M2_01";
                };
            };
            class MotorizedTeam : Triple
            {
                class Unit0 : Unit0
                {
                    vehicle = "CFP_O_ALQAEDA_Offroad_M2_01";
                };
                class Unit1 : Unit1
                {
                    vehicle = "CFP_O_ALQAEDA_Rifleman_01";
                };
                class Unit2 : Unit2
                {
                    vehicle = "CFP_O_ALQAEDA_Rifleman_01";
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
                    vehicle = "CFP_O_ALQAEDA_Offroad_M2_01";
                };
            };
        };
        class Arid : SemiArid
        {
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
};