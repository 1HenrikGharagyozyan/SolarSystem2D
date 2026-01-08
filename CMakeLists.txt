cmake_minimum_required(VERSION 3.16)

project(SolarSystem2D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(SolarSystem2D
    src/main.cpp
)
