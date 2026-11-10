# Roadmap

Versions are sequential; no version is complete until its acceptance tests pass. Parallel workstreams may progress, but do not change the version number by themselves.

1. **v0.1b — foundation:** repository layout, C++17 build, CPU-state scaffold and host CI.
2. **v0.2b — CPU foundation:** register helpers, instruction byte reader, decoder framework and unit tests.
3. **v0.3b — integer execution:** scoped x86-64 integer instructions, flags and branch tests.
4. **v0.4b — guest memory:** address translation, bounds/permissions and fault tests.
5. **v0.5b — exceptions/control flow:** exception model, interrupt research and tests.
6. **v0.6b — system abstractions:** threads, synchronization, timers and OS-service interfaces.
7. **v0.7b — graphics research:** documented GCN subset and GCN-to-Xenos feasibility experiments.
8. **v0.8b — audio/input/storage:** isolated interfaces and host tests.
9. **v0.9b — Xbox 360 integration:** verified Xenon toolchain, entry point and target measurements.
10. **v1.0b — experimental package:** reproducible CI-produced `default.xex`, only if target build and hardware validation succeed.

## Parallel workstreams

- **Save/load state:** CPU snapshot with version and checksum exists; RAM and device snapshots remain future work.
- **Game library:** in-memory game records, favorites, title search, category and genre filtering exist; filesystem scanning and persistent metadata remain future work.
- **Settings:** preset model and per-game preset selection exist; renderer controls and UI are not connected.
- **Cover system:** folder/cache plan exists; metadata provider, downloads, image decoding and network integration are pending.
- **Aurora-inspired UI:** design plan only; cover grid, details, navigation and widgets are pending.
- **Startup presentation:** configurable splash/audio paths exist; playback and custom media assets are pending.
- **Xbox 360 build:** toolchain investigation only; ELF/XEX generation and console validation are pending.

## Acceptance rule

A documented interface or source module is not equivalent to a working feature. Every feature needs tests; Xbox 360-specific claims require a real target build and, where applicable, hardware testing.