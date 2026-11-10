#include "game_library.hpp"
#include <algorithm>
#include <cctype>
#include <utility>

namespace onex360::library {
namespace {
std::string lower(std::string value) {
    std::transform(value.begin(),value.end(),value.begin(),
        [](unsigned char c){return static_cast<char>(std::tolower(c));});
    return value;
}
}
void GameLibrary::add(GameEntry game) {
    auto it=std::find_if(games_.begin(),games_.end(),[&](const GameEntry& g){return g.game_path==game.game_path;});
    if(it==games_.end()) games_.push_back(std::move(game)); else *it=std::move(game);
}
bool GameLibrary::set_favorite(const std::string& path, bool favorite) {
    auto it=std::find_if(games_.begin(),games_.end(),[&](const GameEntry& g){return g.game_path==path;});
    if(it==games_.end()) return false;
    it->favorite=favorite; return true;
}
std::vector<GameEntry> GameLibrary::search(const std::string& query, bool favorites_only) const {
    const auto needle=lower(query);
    std::vector<GameEntry> result;
    for(const auto& game:games_) {
        if(favorites_only && !game.favorite) continue;
        if(needle.empty() || lower(game.title).find(needle)!=std::string::npos) result.push_back(game);
    }
    return result;
}
}