#include "settings.hpp"
namespace onex360::config {
RenderPreset preset_for_game(const Settings& settings, const std::string& game_id) {
    for (const auto& item : settings.per_game)
        if (item.game_id == game_id) return item.preset;
    return settings.default_preset;
}
}