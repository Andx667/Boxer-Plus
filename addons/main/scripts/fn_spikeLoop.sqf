/*
    hawks_fnc_spikeLoop - Spike-Klappen des IFV.

    Der Werfer bleibt zu, solange kein Spike angewaehlt ist, kein Spike im
    Werfer liegt oder gerade nachgeladen wird; sonst fahren die Klappen auf.
    Zustand kommt aus weaponState des Hauptturms:
        [Waffe, Muendung, Modus, Magazin, Schuss, Rundenladephase, Magazinladephase]

    Feuersperre: solange die Klappen noch nicht ganz offen stehen, wird die
    Rundenladephase des Titan immer wieder auf 1 gesetzt (reloadTime der Waffe
    ist 1 s, der PFH laeuft alle 0.1 s - die Sperre reisst nicht ab).
    Stehen die Klappen, geht sie auf 0.02 -> schussbereit nach 20 ms.

    Laeuft als CBA-PerFrameHandler (Delay 0.1 s) statt als sleep-Schleife, kehrt
    also sofort zurueck; der Handler entfernt sich selbst, wenn das Fahrzeug stirbt.

    Lokal je Client (animateSource ist lokal), wie fn_hatchLoop. Nur fuer
    Fahrzeuge mit hawks_spikeDoors = 1 in der Config.
*/
params ["_veh"];
if (getNumber (configOf _veh >> "hawks_spikeDoors") != 1) exitWith {};

[{
    params ["_args", "_handle"];
    _args params ["_veh", "_state"];
    // _state: [letzter Klappenwert, Feuersperre aktiv]

    if (!alive _veh) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
    };

    // unaere Form [Fahrzeug, Turmpfad] - die binaere erwartet einen Waffennamen
    private _ws = weaponState [_veh, [0]];
    private _spike = (_ws select 0) == "bwa3_land_spikeLR_atgm";
    private _offen = parseNumber (
        _spike
        && {(_ws select 4) > 0}
        && {(_ws select 6) == 0}
    );
    if (_offen != _state select 0) then {
        _state set [0, _offen];
        _veh animateSource ["spike_doors", _offen];
    };

    private _mann = _veh turretUnit [0];
    if (_spike && {!isNull _mann}) then {
        if ((_veh animationSourcePhase "spike_doors") < 0.98) then {
            _veh setWeaponReloadingTime [_mann, "bwa3_land_spikeLR_atgm", 1];
            _state set [1, true];
        } else {
            if (_state select 1) then {
                _state set [1, false];
                _veh setWeaponReloadingTime [_mann, "bwa3_land_spikeLR_atgm", 0.02];
            };
        };
    } else {
        _state set [1, false];
    };
}, 0.1, [_veh, [-1, false]]] call CBA_fnc_addPerFrameHandler;
