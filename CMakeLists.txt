cmake_minimum_required(VERSION 3.14)
project(chip8)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
find_library(SDL2_LIBRARY NAME SDL2::SDL2)
add_executable(
    chip8
    Source/Chip8.cpp
    Source/Main.cpp
    Source/Platform.cpp
    Source/Chip8instruct.cpp
)


target_compile_options(chip8 PRIVATE -Wall)

target_link_libraries(chip8 ${SDL2_LIBRARY})