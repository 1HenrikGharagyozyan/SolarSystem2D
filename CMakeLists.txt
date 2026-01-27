cmake_minimum_required(VERSION 3.20)

project(SolarSystem2D LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------
# Submodules
# --------------------------
add_subdirectory(external/glfw)

# --------------------------
# GLAD as vendor
# --------------------------
add_library(glad STATIC
    external/glad/src/glad.c
)

target_include_directories(glad
    PUBLIC
        external/glad/include
)

# --------------------------
# Executable
# --------------------------
add_executable(SolarSystem2D
    src/main.cpp
    src/core/Application.cpp
    src/core/Application.hpp
    src/core/Window.cpp
    src/core/Window.hpp
    src/core/Time.cpp
    src/core/Time.hpp
    src/renderer/Renderer.cpp
    src/renderer/Renderer.hpp
    src/renderer/RenderCommand.cpp
    src/renderer/RenderCommand.hpp
    src/renderer/Camera.hpp
)

target_include_directories(SolarSystem2D
    PRIVATE
        src
        external/glad/include
)

# --------------------------
# Linking
# --------------------------
target_link_libraries(SolarSystem2D
    PRIVATE
        glad
        glfw
        GL
)
