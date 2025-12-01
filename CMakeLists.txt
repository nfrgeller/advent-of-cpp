cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")

project(AdventOfCode2025)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

file(GLOB DAY_SOURCES "src/day*.cpp")
foreach(DAY_SOURCE ${DAY_SOURCES})
    get_filename_component(DAY_NAME ${DAY_SOURCE} NAME_WE)
    add_executable(${DAY_NAME} ${DAY_SOURCE})
endforeach()
