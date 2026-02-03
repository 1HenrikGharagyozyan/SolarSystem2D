#pragma once

#include <glm/glm.hpp>

namespace SolarSystem2D
{

    class OrthographicCamera;

    class DebugRenderer2D
    {
    public:
        static void init();
        static void shutdown();

        static void beginScene(const OrthographicCamera& camera);
        static void endScene();

        static void drawCircle(const glm::vec2& center, float radius, 
                    const glm::vec4& color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), int segments = 64);

    };

}