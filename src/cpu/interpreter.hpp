#pragma once
#include "cpu_state.hpp"
#include "decoder.hpp"
#include <cstdint>
#include <vector>

namespace onex360::cpu {
enum class StepResult { Executed, Halted, DecodeError, Unsupported };
StepResult step(CpuState& state, const std::vector<std::uint8_t>& code);
}