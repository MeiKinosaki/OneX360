# Testing and evidence

## Host test targets

- `cpu_state`: CPU state default initialization.
- `features`: CPU-only save/load round-trip, game-library search/favorites/category/genre filters and per-game preset selection.
- `cpu_decoder`: selected opcode decoding and initial interpreter steps.

GitHub Actions builds the portable C++17 library and runs CTest on a Linux host.

## Evidence levels

- **Code written:** source exists in GitHub.
- **Host build passed:** CI compiled the host targets.
- **Host tests passed:** CTest reports all named tests passed.
- **Xbox 360 build passed:** a verified Xenon toolchain produced a target artifact.
- **XEX validated:** the `default.xex` artifact was inspected and confirmed valid.
- **Hardware tested:** it was launched and observed on an Xbox 360.

These are separate claims. No Xbox 360 build, XEX, or hardware test is currently confirmed.