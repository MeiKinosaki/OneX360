#include "interpreter.hpp"

namespace onex360::cpu {
StepResult step(CpuState& state, const std::vector<std::uint8_t>& code) {
    if (state.halted) return StepResult::Halted;
    if (state.rip>static_cast<std::uint64_t>(code.size())) return StepResult::DecodeError;
    const auto decoded=decode_one(code,static_cast<std::size_t>(state.rip));
    if (!decoded.ok) return StepResult::DecodeError;
    const auto& ins=decoded.instruction;
    switch(ins.opcode) {
        case Opcode::Nop:
            state.rip+=ins.length; return StepResult::Executed;
        case Opcode::Halt:
            state.rip+=ins.length; state.halted=true; return StepResult::Halted;
        case Opcode::MovRegImm:
            if(ins.reg>=16) return StepResult::Unsupported;
            state.gpr[ins.reg]=ins.immediate;
            state.rip+=ins.length; return StepResult::Executed;
        case Opcode::Ret:
            return StepResult::Unsupported;
        default:
            return StepResult::Unsupported;
    }
}
}