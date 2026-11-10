# Testing and evidence

## Current automated test scope

The GitHub Actions workflow configures CMake, compiles the portable host code, and runs CTest. The tests cover CPU-state defaults, CPU-only save/load round-trip, game-library search/favorites/category/genre filters, and per-game preset selection.

## Evidence labels

- **Code written:** source exists in the repository.
- **Host build passed:** CI compiled the host target.
- **Host tests passed:** named tests ran successfully on CI.
- **Xbox 360 build passed:** a verified Xenon-compatible toolchain produced a target artifact.
- **XEX validated:** the produced `default.xex` was inspected and confirmed valid.
- **Hardware tested:** the artifact was launched on Xbox 360 hardware and observed.

These are separate claims. Current host tests do not cover Xbox One instruction execution, guest RAM snapshots, GPU state, cover downloads, UI rendering, audio playback, or a `default.xex`.