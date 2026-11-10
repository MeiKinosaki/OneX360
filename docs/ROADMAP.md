# Roadmap

Stages are sequential; later stages do not count as complete until their prerequisites and tests pass.

1. **v0.1b — project foundation:** repository layout, C++17 build, CPU-state scaffold, host CI.
2. **v0.2b — CPU foundation:** register access helpers, instruction byte reader, decoder framework and unit tests.
3. **v0.3b — integer execution:** carefully scoped x86-64 integer instructions, flags and branch tests.
4. **v0.4b — guest memory:** address translation model, bounds/permissions and fault tests.
5. **v0.5b — exceptions and control flow:** exception model, interrupts research and deterministic tests.
6. **v0.6b — system abstractions:** threads, synchronization, timers and file interface stubs with tests.
7. **v0.7b — graphics research:** documented GCN command/resource subset and Xenos feasibility experiments.
8. **v0.8b — audio/input/storage:** isolated interfaces and host-side tests.
9. **v0.9b — Xbox 360 integration:** verified Xenon toolchain, target entry point and memory/performance measurements.
10. **v1.0b — experimental package:** reproducible CI-produced `default.xex`, only if the target build and hardware validation succeed.

This roadmap is a plan, not a claim that these stages are implemented. No stages are skipped; scope may be revised when measurements show a design is infeasible.