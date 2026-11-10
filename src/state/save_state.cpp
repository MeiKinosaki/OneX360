#include "save_state.hpp"
#include <array>
#include <cstdint>
#include <fstream>
#include <vector>

namespace onex360::state {
namespace {
constexpr std::array<unsigned char, 8> magic{{'O','N','X','S','T','0','1','\0'}};
constexpr std::uint32_t format_version = 1;

void put64(std::vector<unsigned char>& out, std::uint64_t v) {
    for (unsigned i=0;i<8;++i) out.push_back(static_cast<unsigned char>((v>>(i*8))&0xff));
}
void put32(std::vector<unsigned char>& out, std::uint32_t v) {
    for (unsigned i=0;i<4;++i) out.push_back(static_cast<unsigned char>((v>>(i*8))&0xff));
}
std::uint64_t get64(const std::vector<unsigned char>& b, std::size_t& p) {
    std::uint64_t v=0; for(unsigned i=0;i<8;++i) v|=std::uint64_t(b[p++])<<(i*8); return v;
}
std::uint32_t get32(const std::vector<unsigned char>& b, std::size_t& p) {
    std::uint32_t v=0; for(unsigned i=0;i<4;++i) v|=std::uint32_t(b[p++])<<(i*8); return v;
}
std::uint32_t crc32(const std::vector<unsigned char>& data) {
    std::uint32_t crc=0xffffffffu;
    for (auto byte:data) {
        crc^=byte;
        for(int bit=0;bit<8;++bit) crc=(crc>>1)^((crc&1)?0xedb88320u:0u);
    }
    return ~crc;
}
std::vector<unsigned char> payload(const cpu::CpuState& s) {
    std::vector<unsigned char> p;
    for(auto v:s.gpr) put64(p,v);
    put64(p,s.rip); put64(p,s.rflags); put64(p,s.rsp); put64(p,s.rbp);
    p.push_back(s.halted?1:0);
    return p;
}
}
bool save_cpu_state(const std::string& path, const cpu::CpuState& state, std::string& error) {
    auto data=payload(state);
    std::vector<unsigned char> file(magic.begin(),magic.end());
    put32(file,format_version); put32(file,static_cast<std::uint32_t>(data.size()));
    file.insert(file.end(),data.begin(),data.end()); put32(file,crc32(data));
    std::ofstream out(path,std::ios::binary|std::ios::trunc);
    if(!out){error="cannot open save-state file for writing";return false;}
    out.write(reinterpret_cast<const char*>(file.data()),static_cast<std::streamsize>(file.size()));
    if(!out){error="failed while writing save-state file";return false;}
    error.clear(); return true;
}
bool load_cpu_state(const std::string& path, cpu::CpuState& state, std::string& error) {
    std::ifstream in(path,std::ios::binary);
    if(!in){error="cannot open save-state file";return false;}
    std::vector<unsigned char> file((std::istreambuf_iterator<char>(in)),{});
    constexpr std::size_t expected_payload=16*8+4*8+1;
    if(file.size()!=8+4+4+expected_payload+4){error="invalid save-state size";return false;}
    for(std::size_t i=0;i<magic.size();++i) if(file[i]!=magic[i]){error="invalid save-state signature";return false;}
    std::size_t pos=8;
    if(get32(file,pos)!=format_version){error="unsupported save-state version";return false;}
    auto size=get32(file,pos);
    if(size!=expected_payload){error="invalid save-state payload length";return false;}
    std::vector<unsigned char> data(file.begin()+pos,file.begin()+pos+size);
    pos+=size;
    if(get32(file,pos)!=crc32(data)){error="save-state checksum mismatch";return false;}
    cpu::CpuState candidate{};
    std::size_t p=0;
    for(auto& v:candidate.gpr) v=get64(data,p);
    candidate.rip=get64(data,p); candidate.rflags=get64(data,p);
    candidate.rsp=get64(data,p); candidate.rbp=get64(data,p);
    if(data[p]>1){error="invalid halted flag";return false;}
    candidate.halted=data[p]!=0;
    state=candidate; error.clear(); return true;
}
}