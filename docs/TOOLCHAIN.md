# Xbox 360 toolchain strategy

The first CI workflow is host-only. It does not target PowerPC Xenon.

Target build work is gated on selecting and validating a legally obtained, reproducible toolchain. Candidate paths to investigate include a compatible Xbox 360 SDK environment or an open-source libxenon-based toolchain. They are not interchangeable and must not be assumed to produce a loadable RGH XEX without verification.

## Planned artifacts

- `Xenon.elf`: optional intermediate/debug ELF if supported by the selected toolchain.
- `default.xex`: intended packaged Xbox 360 executable.

Both artifacts are future goals, not currently generated. The target pipeline must record compiler versions, linker commands, conversion steps, artifact hashes and validation results.