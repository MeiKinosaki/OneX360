#pragma once
#include <string>
#include <vector>

namespace onex360::library {
struct GameEntry {
    std::string title;
    std::string game_path;
    std::string cover_path;
    bool favorite{false};
    std::string category;
    std::string genre;
};
struct GameFilter {
    std::string text;
    std::string category;
    std::string genre;
    bool favorites_only{false};
};
class GameLibrary {
public:
    void add(GameEntry game);
    bool set_favorite(const std::string& game_path, bool favorite);
    std::vector<GameEntry> search(const std::string& query, bool favorites_only=false) const;
    std::vector<GameEntry> filter(const GameFilter& filter) const;
    const std::vector<GameEntry>& entries() const noexcept { return games_; }
private:
    std::vector<GameEntry> games_;
};
}