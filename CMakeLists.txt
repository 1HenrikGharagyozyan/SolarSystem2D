cmake_minimum_required(VERSION 3.16)

project(SolarSystem2D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(SolarSystem2D ${SOURCES})

target_include_directories(SolarSystem2D
    PUBLIC
        include
)
