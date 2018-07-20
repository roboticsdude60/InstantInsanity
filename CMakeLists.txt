cmake_minimum_required(VERSION 3.8)
project(MasonsCubes)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Cube.cpp Cube.h)
add_executable(MasonsCubes ${SOURCE_FILES})