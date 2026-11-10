# Testing and evidence

## Current automated checks

GitHub Actions configures CMake, compiles the portable host library/test executable, and runs CTest.

## Evidence labels

- **Code written:** source exists in the repository.
- **Host test passed:** a named test ran successfully on the CI host.
- **Xbox 360 build passed:** a verified Xenon-compatible toolchain produced the target artifact.
- **XEX validated:** the produced `default.xex` was inspected and confirmed valid.
- **Hardware tested:** the artifact was launched on Xbox 360 hardware and observed.

These are separate claims. The current workflow does not produce or validate a `default.xex`.