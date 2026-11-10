# Architecture — v0.1b

## Host/target split

The initial code is portable C++17 and can be tested on a normal CI host. The eventual Xbox 360 target is PowerPC Xenon and must be built with a verified Xbox 360-compatible toolchain before any XEX claim is made.

## Planned subsystems

- **CPU:** x86-64 architectural state, decoder, instruction semantics, exceptions and flags.
- **Memory:** guest virtual address model, page permissions, translation and fault handling.
- **GPU:** abstract command/resource model, followed by a research-driven GCN-to-Xenos translation layer.
- **System:** threads, timers, synchronization, files, input, audio and selected OS services.
- **Xbox 360 platform:** entry point, memory budgeting, controller/input integration and XEX packaging.

## First implementation boundary

v0.1b defines only a minimal CPU state structure. There is no decoder, instruction execution, guest memory, GPU, audio, system-call layer, or boot path.