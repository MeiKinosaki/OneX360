#include "cpu/decoder.hpp"
#include "cpu/interpreter.hpp"
#include <iostream>
#include <vector>

#define CHECK(x) do { if(!(x)){std::cerr<<"Failed: " #x " line "<<__LINE__<<"\n";return 1;} } while(false)

int main() {
    using namespace onex360::cpu;
    {
        const std::vector<std::uint8_t> code{0x90};
        auto d=decode_one(code);
        CHECK(d.ok && d.instruction.opcode==Opcode::Nop && d.instruction.length==1);
    }
    {
        const std::vector<std::uint8_t> code{0x48,0xb8,0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11};
        auto d=decode_one(code);
        CHECK(d.ok && d.instruction.opcode==Opcode::MovRegImm);
        CHECK(d.instruction.reg==0 && d.instruction.immediate==0x1122334455667788ULL);
        CHECK(d.instruction.length==10);
    }
    {
        const std::vector<std::uint8_t> code{0x49,0xb9,0x01,0,0,0,0,0,0,0};
        auto d=decode_one(code);
        CHECK(d.ok && d.instruction.reg==9 && d.instruction.immediate==1);
    }
    {
        const std::vector<std::uint8_t> code{0x48,0xb8,0x01};
        CHECK(!decode_one(code).ok);
    }
    {
        const std::vector<std::uint8_t> code{0x90,0x48,0xb8,0x2a,0,0,0,0,0,0,0,0xf4};
        CpuState state{};
        CHECK(step(state,code)==StepResult::Executed && state.rip==1);
        CHECK(step(state,code)==StepResult::Executed);
        CHECK(state.gpr[0]==42 && state.rip==11);
        CHECK(step(state,code)==StepResult::Halted && state.halted);
        CHECK(step(state,code)==StepResult::Halted);
    }
    return 0;
}