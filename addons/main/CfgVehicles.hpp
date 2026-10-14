class CfgVehicles {
    // Base chain, declared like the Boxer mod does so the patch merges into the real classes.
    class Car_F;
    class Wheeled_APC_F: Car_F {
        class Turrets {
            class MainTurret;
        };
    };
    class Hawks_GTK_Boxer_base: Wheeled_APC_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
        // BWA3 Panzertruppe crew instead of B_crew_F (crew is one class for all seats)
        crew = "BWA3_Crew_Fleck";
        typicalCargo[] = {"BWA3_Crew_Fleck"};

        // Inventory copied from the BWA3 Puma (BWA3_Puma_base). The Medical and the AUS
        // variants are reset further down.
        class TransportMagazines {
            class _xx_BWA3_30Rnd_556x45_G36 {
                magazine = "BWA3_30Rnd_556x45_G36";
                count = 24;
            };
            class _xx_BWA3_200Rnd_556x45 {
                magazine = "BWA3_200Rnd_556x45";
                count = 6;
            };
            class _xx_BWA3_DM25 {
                magazine = "BWA3_DM25";
                count = 10;
            };
            class _xx_BWA3_DM32_Orange {
                magazine = "BWA3_DM32_Orange";
                count = 8;
            };
        };

        class TransportWeapons {
            class _xx_BWA3_G36KA2_RSAS_pointer {
                weapon = "BWA3_G36KA2_RSAS_pointer";
                count = 2;
            };
            class _xx_BWA3_MG4_ZO4x30_pointer {
                weapon = "BWA3_MG4_ZO4x30_pointer";
                count = 1;
            };
            class _xx_BWA3_PzF3_Tandem_Loaded {
                weapon = "BWA3_PzF3_Tandem_Loaded";
                count = 2;
            };
        };

        class TransportItems {
            class _xx_FirstAidKit {
                name = "FirstAidKit";
                count = 10;
            };
        };

        // ACE viewports: rear view for the troop compartment, fed by the Boxer's own
        // reverse camera point (pip2_pos, same as the RevCam render target).
        // No type = periscope strip with a wide 0.75 field of view (type "screen" is a
        // fixed, narrow 0.25 FOV monitor picture). It opens when a seated passenger
        // (seats at x = +-0.7, y -2.0 / -2.56) looks at the ramp: the screen point is the
        // vehicle's cargo get-in point, which sits at the rear. If the trigger spot is
        // off, replace it with measured model coordinates, e.g. screenLocation[] =
        // {0, -3.5, 1.2}, and tune maxDistance (reach from the eye to that point).
        // The camera can only be moved (camLocation[] = {x, y, z}, e.g. from
        // (vehicle player) selectionPosition ["pip2_pos", "Memory"]); ACE gives it no pitch.
        class ace_viewports {
            class rear_view {
                camLocation = "pip2_pos";
                camAttach = 180;
                screenLocation = "pos cargo";
                maxDistance = 4;
                roles[] = {"cargo"};
            };
        };
    };
    class Hawks_GTK_Boxer_HMG: Hawks_GTK_Boxer_base {
        // Longer reach, like the Medical. The HMG's seats (transportSoldier = 0) are
        // CargoTurret_xx classes derived from MainTurret, so ACE sees them as role "turret",
        // not "cargo". (GMG and its camo variants inherit this; RCH155 overrides it below.)
        class ace_viewports: ace_viewports {
            class rear_view: rear_view {
                roles[] = {"cargo", "turret"};
                maxDistance = 6;
            };
        };
    };
    class Hawks_GTK_Boxer_HMG_Sand: Hawks_GTK_Boxer_HMG {
        crew = "BWA3_Crew_Tropen";
        typicalCargo[] = {"BWA3_Crew_Tropen"};
    };
    class Hawks_GTK_Boxer_GMG: Hawks_GTK_Boxer_HMG {};
    class Hawks_GTK_Boxer_GMG_Sand: Hawks_GTK_Boxer_GMG {
        crew = "BWA3_Crew_Tropen";
        typicalCargo[] = {"BWA3_Crew_Tropen"};
    };
    class Hawks_GTK_Boxer_RCH155: Hawks_GTK_Boxer_HMG {
        // No rear view on the RCH155: an empty class replaces the inherited viewports.
        class ace_viewports {};
    };
    class Hawks_GTK_Boxer_RCH155_Sand: Hawks_GTK_Boxer_RCH155 {
        crew = "BWA3_Crew_Tropen";
        typicalCargo[] = {"BWA3_Crew_Tropen"};
    };

    // _Sand, _Snow and _AUS inherit this turret and need no entry.
    class Hawks_GTK_Boxer_IFV: Hawks_GTK_Boxer_HMG {
        // The IFV keeps the base reach of 4 m and its real cargo seats (Medical sets its own below).
        class ace_viewports: ace_viewports {
            class rear_view: rear_view {
                roles[] = {"cargo"};
                maxDistance = 4;
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = {"Hawks_autocannon_30mm_CTWS", "Hawks_MG_762_coax", "bwa3_land_spikeLR_atgm", "SmokeLauncher"};
                magazines[] = {"Hawks_140Rnd_30mm_HE_Tracer_Red", "Hawks_140Rnd_30mm_HE_Tracer_Red", "60Rnd_30mm_APFSDS_shells_Tracer_Red", "60Rnd_30mm_APFSDS_shells_Tracer_Red", "Hawks_200Rnd_762x51_Belt_Red", "Hawks_200Rnd_762x51_Belt_Red", "Hawks_200Rnd_762x51_Belt_Red", "Hawks_200Rnd_762x51_Belt_Red", "bwa3_mells_spikeLR_2rnd_puma", "bwa3_mells_spikeLR_2rnd_puma", "SmokeLauncherMag"};
            };
        };
        class RenderTargets {
            class Missiles_revolving {
                weapon = "bwa3_land_spikeLR_atgm";
            };
        };
    };

    class Hawks_GTK_Boxer_IFV_Sand: Hawks_GTK_Boxer_IFV {
        crew = "BWA3_Crew_Tropen";
        typicalCargo[] = {"BWA3_Crew_Tropen"};
    };

    // Medical: Sanitaeter (combat life saver) as crew
    class Hawks_GTK_Boxer_Medical: Hawks_GTK_Boxer_IFV {
        crew = "BWA3_Medic_Fleck";
        typicalCargo[] = {"BWA3_Medic_Fleck"};

        // No Puma inventory on the Medical: its own TransportItems (first aid, Medikit) stay.
        class TransportMagazines {};
        class TransportWeapons {};

        // Rear view only for the commander and medic turret seats (the three cargo
        // seats are patient places), from further away: those seats are further from
        // the ramp than the troop bench. Roles: commander turret = "commander", medic
        // turret = "turret". Measure the seats with
        // (vehicle player) worldToModel (getPosATL player) and tune maxDistance.
        class ace_viewports: ace_viewports {
            class rear_view: rear_view {
                roles[] = {"commander", "turret"};
                maxDistance = 6;
            };
        };
    };
    class Hawks_GTK_Boxer_Medical_Sand: Hawks_GTK_Boxer_Medical {
        crew = "BWA3_Medic_Tropen";
        typicalCargo[] = {"BWA3_Medic_Tropen"};
    };

    // AUS keeps the vanilla crew and the empty vanilla inventory
    class Hawks_GTK_Boxer_HMG_AUS: Hawks_GTK_Boxer_HMG {
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        crew = "B_crew_F";
        typicalCargo[] = {"B_crew_F"};
    };
    class Hawks_GTK_Boxer_GMG_AUS: Hawks_GTK_Boxer_GMG {
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        crew = "B_crew_F";
        typicalCargo[] = {"B_crew_F"};
    };
    class Hawks_GTK_Boxer_IFV_AUS: Hawks_GTK_Boxer_IFV {
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        crew = "B_crew_F";
        typicalCargo[] = {"B_crew_F"};
    };
    class Hawks_GTK_Boxer_Medical_AUS: Hawks_GTK_Boxer_Medical {
        crew = "B_crew_F";
        typicalCargo[] = {"B_crew_F"};
    };
    class Hawks_GTK_Boxer_RCH155_AUS: Hawks_GTK_Boxer_RCH155 {
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        crew = "B_crew_F";
        typicalCargo[] = {"B_crew_F"};
    };
};
