#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace onex360::cpu {
enum class Opcode { Invalid, Nop, Halt, Ret, MovRegImm };
struct DecodedInstruction {
    Opcode opcode{Opcode::Invalid};
    std::uint8_t reg{0};
    std::uint64_t immediate{0};
    std::uint8_t length{0};
};
struct DecodeResult {
    DecodedInstruction instruction{};
    bool ok{false};
    const char* error{"invalid instruction"};
};
DecodeResult decode_one(const std::vector<std::uint8_t>& bytes, std::size_t offset=0);
}