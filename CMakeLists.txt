cmake_minimum_required(VERSION 3.20)

project(SolarSystem2D LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/glfw)

add_library(glad STATIC
    external/glad/src/glad.c
)

target_include_directories(glad
    PUBLIC
        external/glad/include
)

add_executable(SolarSystem2D
    src/main.cpp
    src/core/Application.cpp
    src/core/Window.cpp
    src/core/Time.cpp
    src/renderer/RenderCommand.cpp
    src/renderer/Renderer.cpp
    src/renderer/Buffer.cpp
    src/renderer/VertexArray.cpp
    src/renderer/Shader.cpp
    src/renderer/Renderer2D.cpp
    src/renderer/OrthographicCamera.cpp
    src/core/Transform.cpp
)

target_include_directories(SolarSystem2D
    PRIVATE 
        src
        external/glm
)

target_link_libraries(SolarSystem2D
    PRIVATE 
        glad 
        glfw 
        GL
)
