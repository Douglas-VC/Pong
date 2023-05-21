cmake_minimum_required(VERSION 3.24)
project(Pong)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED SDL2)

add_executable(Pong main.cpp Game.cpp Game.h)

target_link_libraries(Pong PRIVATE SDL2)
