#include "cpu/cpu_state.hpp"
#include <cassert>

int main() {
    onex360::cpu::CpuState state{};
    assert(state.rip == 0);
    assert(state.rflags == 2);
    assert(state.halted == false);
    for (auto value : state.gpr) assert(value == 0);
    return 0;
}