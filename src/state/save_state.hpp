#pragma once
#include "cpu/cpu_state.hpp"
#include <string>

namespace onex360::state {
// v1 snapshot currently serializes CPU architectural state only.
// Device/GPU/RAM snapshots will be added when those subsystems exist.
bool save_cpu_state(const std::string& path, const cpu::CpuState& state, std::string& error);
bool load_cpu_state(const std::string& path, cpu::CpuState& state, std::string& error);
}