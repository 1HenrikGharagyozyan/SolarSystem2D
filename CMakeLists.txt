cmake_minimum_required(VERSION 3.20)

project(SolarSystem2D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/glfw)

add_executable(SolarSystem2D
    src/main.cpp
    src/core/Application.cpp
    src/core/Window.cpp
)

target_include_directories(SolarSystem2D
    PRIVATE
        src
        external/glfw/include
)

target_link_libraries(SolarSystem2D
    glfw
)



