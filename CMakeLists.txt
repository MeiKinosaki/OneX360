cmake_minimum_required(VERSION 3.16)
project(OneX360 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(onex360_core
    src/cpu/cpu_state.cpp
)
target_include_directories(onex360_core PUBLIC src)

enable_testing()
add_executable(onex360_tests tests/test_cpu_state.cpp)
target_link_libraries(onex360_tests PRIVATE onex360_core)
add_test(NAME onex360_cpu_state COMMAND onex360_tests)