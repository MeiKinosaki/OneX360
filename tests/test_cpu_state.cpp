#include "cpu/cpu_state.hpp"
#include <iostream>

int main() {
    onex360::cpu::CpuState state{};
    if (state.rip != 0 || state.rflags != 2 || state.halted) {
        std::cerr << "CPU state defaults are incorrect\n"; return 1;
    }
    for (auto value : state.gpr) {
        if (value != 0) { std::cerr << "GPR not zero-initialized\n"; return 1; }
    }
    return 0;
}