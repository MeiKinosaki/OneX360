cmake_minimum_required(VERSION 3.16)
project(OneX360 VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(onex360_core
    src/cpu/cpu_state.cpp
    src/cpu/decoder.cpp
    src/cpu/interpreter.cpp
    src/state/save_state.cpp
    src/library/game_library.cpp
    src/config/settings.cpp
)
target_include_directories(onex360_core PUBLIC src)

enable_testing()
add_executable(test_cpu_state tests/test_cpu_state.cpp)
target_link_libraries(test_cpu_state PRIVATE onex360_core)
add_test(NAME cpu_state COMMAND test_cpu_state)

add_executable(test_features tests/test_features.cpp)
target_link_libraries(test_features PRIVATE onex360_core)
add_test(NAME features COMMAND test_features)

add_executable(test_cpu_decoder tests/test_cpu_decoder.cpp)
target_link_libraries(test_cpu_decoder PRIVATE onex360_core)
add_test(NAME cpu_decoder COMMAND test_cpu_decoder)
