# Roadmap

Versions are sequential. A version is not complete until implementation and acceptance tests pass.

1. **v0.1b — foundation:** repository, portable C++17 build, CPU state, host CI, initial CPU decoder/interpreter and initial feature models.
2. **v0.2b — CPU foundation:** register helpers, instruction byte reader, robust prefix/ModRM/SIB decoder, flags and broader unit tests.
3. **v0.3b — integer execution:** arithmetic, logic, data movement, branches and flag behavior for a scoped x86-64 subset.
4. **v0.4b — guest memory:** address translation, permissions, RAM model and fault tests.
5. **v0.5b — exceptions/control flow:** exceptions, interrupts and deterministic execution tests.
6. **v0.6b — system abstractions:** threads, synchronization, timers and OS-service interfaces.
7. **v0.7b — graphics research:** documented GCN subset and GCN-to-Xenos feasibility experiments.
8. **v0.8b — audio/input/storage:** isolated interfaces and host tests.
9. **v0.9b — Xbox 360 integration:** verified Xenon toolchain, target entry point and target measurements.
10. **v1.0b — experimental package:** reproducible CI-produced `default.xex`, only if target build and hardware validation succeed.

## Parallel feature workstreams

- **Save/load:** CPU-only state snapshot exists; guest RAM and device snapshots are pending.
- **Library:** in-memory favorites/search/category/genre filters exist; directory scanning and persistence are pending.
- **Settings:** quality/performance preset model and per-game override selection exist; actual renderer integration is pending.
- **Cover art:** folder/cache design only; provider integration, downloading, image decoding and network code are pending.
- **UI:** Aurora-inspired design plan only; rendered dashboard and navigation are pending.
- **Startup:** configurable splash/audio paths exist; rendering and playback are pending.
- **Build:** host CI only; Xenon toolchain and ELF/XEX packaging are pending.

No copyrighted startup music or proprietary game content will be bundled without permission. Source scaffolding does not count as a finished user-facing feature.