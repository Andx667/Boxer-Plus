# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

<!-- TEMPLATE: `hemtt publish` looks up the entry whose heading exactly
matches the current project version (see .hemtt/project.toml's
[version] / addons/main/script_version.hpp) -- so before publishing,
rename "[Unreleased]" below to "[X.Y.Z] - YYYY-MM-DD" matching that
version, and start a fresh empty [Unreleased] section above it. -->

## [Unreleased]

## [1.0.0] - 2026-10-14

### Added

- BWA3 MELLS Spike LR (`bwa3_land_spikeLR_atgm`) replaces the Titan AT on the Boxer IFV and its Sand / Snow / AUS / Medical variants: TV camera after launch, mouse-aimed in flight, lofted flight profile. Loadout stays 2 + 2.
- BWA3 crews: `BWA3_Crew_Fleck` (Sand: `BWA3_Crew_Tropen`) on HMG, GMG, IFV and RCH155; `BWA3_Medic_Fleck` (Sand: `BWA3_Medic_Tropen`) on the Medical. AUS keeps `B_crew_F`.
- ACE viewports rear view (proof of concept): passengers look at the ramp to see the Boxer's reverse camera. The IFV uses its cargo seats (4 m reach), the HMG / GMG use their passenger turret seats (6 m), the Medical only the commander and medic seats (6 m). Not on the RCH155.
- BWA3 Puma cargo inventory (rifle and MG4 ammo, DM25 / DM32 grenades, G36 and MG4 with pointer, 2 PzF 3 Tandem, 10 first aid kits) on the HMG, GMG, IFV and RCH155 and their Sand / Snow variants. The Medical keeps its own first aid kits and Medikits, AUS keeps the empty vanilla inventory.

### Changed

- `Hawks_fnc_spikeLoop` overridden to watch the BWA3 weapon (flap / fire-lock logic unchanged); runs as a CBA per-frame handler.
- Requires GTK Boxer, BWMod (BWA3), CBA_A3, ACE3.
