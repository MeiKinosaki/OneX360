#include "decoder.hpp"

namespace onex360::cpu {
DecodeResult decode_one(const std::vector<std::uint8_t>& bytes, std::size_t offset) {
    DecodeResult result{};
    if (offset >= bytes.size()) { result.error="instruction stream exhausted"; return result; }
    std::size_t p=offset;
    bool rex_w=false;
    if ((bytes[p]&0xf0u)==0x40u) {
        rex_w=(bytes[p]&0x08u)!=0;
        ++p;
        if (p>=bytes.size()) { result.error="truncated REX prefix"; return result; }
    }
    const auto opcode=bytes[p++];
    auto& ins=result.instruction;
    if (opcode==0x90) ins.opcode=Opcode::Nop;
    else if (opcode==0xf4) ins.opcode=Opcode::Halt;
    else if (opcode==0xc3) ins.opcode=Opcode::Ret;
    else if (opcode>=0xb8 && opcode<=0xbf) {
        ins.opcode=Opcode::MovRegImm;
        ins.reg=static_cast<std::uint8_t>((opcode-0xb8) | ((rex_w && offset<p && (bytes[offset]&0x01u))?8u:0u));
        const std::size_t width=rex_w?8u:4u;
        if (bytes.size()-p<width) { result.error="truncated MOV immediate"; return result; }
        std::uint64_t value=0;
        for(std::size_t i=0;i<width;++i) value|=std::uint64_t(bytes[p++])<<(i*8);
        ins.immediate=value;
    } else {
        result.error="unsupported opcode";
        return result;
    }
    ins.length=static_cast<std::uint8_t>(p-offset);
    result.ok=true; result.error=nullptr; return result;
}
}