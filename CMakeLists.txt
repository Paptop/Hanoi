cmake_minimum_required(VERSION 3.12)
project(TowerHanoi)

set(CMAKE_CXX_STANDARD 17)

add_executable(TowerHanoi Src/main.cpp Src/Tower.cpp Src/Tower.h)