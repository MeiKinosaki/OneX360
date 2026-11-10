#include "state/save_state.hpp"
#include "library/game_library.hpp"
#include "config/settings.hpp"
#include <cstdio>
#include <iostream>
#include <string>

#define CHECK(condition) do { if (!(condition)) { std::cerr << "Check failed: " #condition << " at line " << __LINE__ << "\n"; return 1; } } while (false)

int main() {
    using namespace onex360;
    cpu::CpuState original{};
    original.gpr[0]=0x123456789abcdef0ULL;
    original.rip=0x1000; original.rsp=0x8000; original.rflags=0x246; original.halted=true;
    const std::string path="onex360_test_state.bin";
    std::string error;
    CHECK(state::save_cpu_state(path,original,error));
    cpu::CpuState restored{};
    CHECK(state::load_cpu_state(path,restored,error));
    CHECK(restored.gpr[0]==original.gpr[0]);
    CHECK(restored.rip==original.rip && restored.rsp==original.rsp);
    CHECK(restored.rflags==original.rflags && restored.halted==original.halted);
    std::remove(path.c_str());

    library::GameLibrary games;
    games.add({"Alpha Test","Games/alpha.xbe","Covers/alpha.png",false,"Homebrew","Utility"});
    games.add({"Beta Demo","Games/beta.iso","Covers/beta.png",true,"Retail","Action"});
    CHECK(games.set_favorite("Games/alpha.xbe",true));
    CHECK(games.search("alpha").size()==1);
    CHECK(games.search("",true).size()==2);
    CHECK(!games.set_favorite("missing",true));
    library::GameFilter byCategory; byCategory.category="retail";
    CHECK(games.filter(byCategory).size()==1);
    library::GameFilter byGenre; byGenre.genre="utility";
    CHECK(games.filter(byGenre).size()==1);
    config::Settings settings;
    CHECK(config::preset_for_game(settings,"alpha")==config::RenderPreset::Balanced);
    settings.per_game.push_back({"alpha",config::RenderPreset::Performance});
    CHECK(config::preset_for_game(settings,"alpha")==config::RenderPreset::Performance);
    CHECK(config::preset_for_game(settings,"beta")==config::RenderPreset::Balanced);
    return 0;
}