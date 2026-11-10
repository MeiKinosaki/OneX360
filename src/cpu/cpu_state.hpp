#pragma once
#include <cstdint>

namespace onex360::cpu {
struct CpuState {
    std::uint64_t gpr[16]{};
    std::uint64_t rip{0};
    std::uint64_t rflags{2};
    std::uint64_t rsp{0};
    std::uint64_t rbp{0};
    bool halted{false};
};
}