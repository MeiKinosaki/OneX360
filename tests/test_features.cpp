#include "state/save_state.hpp"
#include "library/game_library.hpp"
#include <cassert>
#include <cstdio>
#include <string>

int main() {
    using namespace onex360;
    cpu::CpuState original{};
    original.gpr[0]=0x123456789abcdef0ULL;
    original.rip=0x1000; original.rsp=0x8000; original.rflags=0x246; original.halted=true;
    const std::string path="onex360_test_state.bin";
    std::string error;
    assert(state::save_cpu_state(path,original,error));
    cpu::CpuState restored{};
    assert(state::load_cpu_state(path,restored,error));
    assert(restored.gpr[0]==original.gpr[0]);
    assert(restored.rip==original.rip && restored.rsp==original.rsp);
    assert(restored.rflags==original.rflags && restored.halted==original.halted);
    std::remove(path.c_str());

    library::GameLibrary games;
    games.add({"Alpha Test","Games/alpha.xbe","Covers/alpha.png",false});
    games.add({"Beta Demo","Games/beta.iso","Covers/beta.png",true});
    assert(games.set_favorite("Games/alpha.xbe",true));
    assert(games.search("alpha").size()==1);
    assert(games.search("",true).size()==2);
    assert(!games.set_favorite("missing",true));
    return 0;
}