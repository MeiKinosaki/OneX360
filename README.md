# OneX360

Experimental research project exploring Xbox One software emulation on Xbox 360 RGH/JTAG.

- Current version: **v0.1b — in progress**
- Target: Xbox 360 Xenon / Xenos
- Intended package: `default.xex`
- Optional intermediate: `Xenon.elf` if supported by the selected toolchain
- CI currently targets portable host tests only.

## Current source modules

- x86-64 CPU state structure.
- Initial decoder for NOP, HLT, RET (decode only), and MOV register-immediate forms with basic REX handling.
- Initial interpreter for NOP, HLT and MOV register-immediate.
- CPU-only save/load state with format version and CRC32 validation.
- In-memory game library with favorites, title search, category and genre filters.
- Settings model for Performance/Balanced/Quality and per-game overrides.

## Not implemented yet

Full x86-64/Jaguar support, guest RAM/MMU, exceptions, Xbox One system services, GCN graphics translation, audio, controller integration, filesystem scanning, persistent game metadata, cover downloads, Aurora-inspired rendered UI, splash/audio playback, Xbox 360 network support, Xenon toolchain build and XEX packaging.

Xbox One Jaguar x86-64/GCN and Xbox 360 Xenon/Xenos are substantially different. Commercial Xbox One game compatibility is not claimed and may be infeasible on the target hardware.

## Host build

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 2
ctest --test-dir build --output-on-failure
```

The GitHub Actions workflow runs these portable host tests. A green host CI does not establish Xbox 360 build success.

## Documentation

- [Architecture](docs/ARCHITECTURE.md)
- [Roadmap](docs/ROADMAP.md)
- [Compatibility](docs/COMPATIBILITY.md)
- [Testing and evidence](docs/TESTING.md)
- [Xbox 360 toolchain strategy](docs/TOOLCHAIN.md)
- [Front-end and game library](docs/FRONTEND_AND_LIBRARY.md)

Splash screen and audio support will use original or properly licensed assets; copyrighted Xbox One startup media will not be bundled without permission.