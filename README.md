# OneX360

**Experimental Xbox One emulator research project for Xbox 360 (RGH/JTAG).**

- Project version: **v0.1b — still in development**
- Target hardware: Xbox 360 Xenon / Xenos
- Intended final output: `default.xex`
- Optional intermediate: `Xenon.elf`, only if the chosen toolchain supports it
- Current CI target: portable host tests only

## Reality check

Xbox One uses an AMD Jaguar x86-64 CPU and AMD GCN graphics. Xbox 360 uses a PowerPC Xenon CPU and Xenos GPU. Full compatibility would require extensive CPU translation, memory and OS-service emulation, and graphics translation. Commercial Xbox One game compatibility and useful performance on Xbox 360 are not promised.

## Implemented source scaffolding

- Minimal x86-64 CPU state structure (no instruction decoder/executor yet).
- CPU-only save/load state file with version marker and CRC32 integrity check.
- In-memory game library model with favorites, text search, category and genre filters.
- Settings model for Performance/Balanced/Quality profiles and per-game overrides.
- Configurable path defaults and startup splash/user-audio settings.
- CMake host build and GitHub Actions test workflow.

These are source-level modules, not a finished emulator interface. Save states currently contain CPU state only; guest RAM, GPU, audio and device state are not implemented. Game scanning, persistence of library/settings, cover downloading, UI rendering, splash playback, and Xbox 360 network integration are not implemented.

## Build host tests

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

A successful host test does not prove an Xbox 360 build or game compatibility.

## Documentation

- [Architecture](docs/ARCHITECTURE.md)
- [Roadmap](docs/ROADMAP.md)
- [Compatibility status](docs/COMPATIBILITY.md)
- [Testing and evidence](docs/TESTING.md)
- [Xbox 360 toolchain strategy](docs/TOOLCHAIN.md)
- [Front-end and library plan](docs/FRONTEND_AND_LIBRARY.md)

## Startup media

The project will accept original/user-provided splash and audio assets. Copyrighted Xbox One startup video/music will not be bundled without permission.

## License

License not selected yet. Do not assume this project grants redistribution rights to firmware, game files, proprietary SDKs, or copyrighted media.