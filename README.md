# OneX360

**Experimental Xbox One emulator research project for Xbox 360 (RGH/JTAG).**

- Project version: **v0.1b**
- Target hardware: Xbox 360 Xenon / Xenos
- Intended output: `default.xex`
- Status: architecture and initial scaffolding

## Reality check

Xbox One uses an AMD Jaguar x86-64 CPU and AMD GCN graphics. Xbox 360 uses a PowerPC Xenon CPU and Xenos GPU. This project therefore requires substantial CPU instruction translation, memory and system-service emulation, and graphics translation. Running commercial Xbox One games on Xbox 360 hardware is an extremely ambitious research goal; compatibility and performance are not promised.

## Current scope

This first checkpoint establishes a small, host-testable CPU foundation. It does **not** execute Xbox One software and does **not** produce a valid Xbox 360 XEX yet.

## Build host-side tests

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

The GitHub Actions workflow validates the portable code on a standard runner. A green host test is not an Xbox 360 build.

## Documentation

- [Architecture](docs/ARCHITECTURE.md)
- [Roadmap](docs/ROADMAP.md)
- [Compatibility status](docs/COMPATIBILITY.md)
- [Testing and evidence](docs/TESTING.md)

## License

License not selected yet. Do not assume this project grants redistribution rights to Xbox One firmware, game files, or proprietary SDKs.