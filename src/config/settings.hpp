#pragma once
#include <string>
#include <vector>

namespace onex360::config {
enum class RenderPreset { Performance, Balanced, Quality };
struct PerGamePreset {
    std::string game_id;
    RenderPreset preset{RenderPreset::Balanced};
};
struct StoragePaths {
    std::string games{"Hdd1:\\Emulators\\OneX360\\Games"};
    std::string covers{"Hdd1:\\Emulators\\OneX360\\Covers"};
    std::string saves{"Hdd1:\\Emulators\\OneX360\\Saves"};
    std::string config{"Hdd1:\\Emulators\\OneX360\\Config"};
};
struct StartupPresentation {
    bool show_splash{true};
    bool play_user_audio{false};
    std::string splash_image;
    std::string audio_file;
};
struct Settings {
    RenderPreset default_preset{RenderPreset::Balanced};
    StoragePaths paths{};
    StartupPresentation startup{};
    std::vector<PerGamePreset> per_game{};
};
RenderPreset preset_for_game(const Settings& settings, const std::string& game_id);
}