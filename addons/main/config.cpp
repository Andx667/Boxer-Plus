#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        author = AUTHOR;
        url = "https://github.com/Andx667/boxer_acespike";
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main", "Hawks_GTK_Boxer", "bwa3_mells", "bwa3_units", "ace_missileguidance", "ace_viewports"};
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        VERSION_CONFIG;
    };
};
// Replace the IFV's flap/fire-lock script with a copy that watches the BWA3 Spike weapon.
class CfgFunctions {
    class Hawks {
        class Lights {
            class spikeLoop {
                file = "\andx\boxer_acespike\addons\main\scripts\fn_spikeLoop.sqf";
            };
        };
    };
};

#include "CfgVehicles.hpp"
