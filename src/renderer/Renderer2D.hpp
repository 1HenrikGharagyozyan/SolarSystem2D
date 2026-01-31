#pragma once

#include "OrthographicCamera.hpp"
#include "core/Transform.hpp"

namespace SolarSystem2D
{

    class Renderer2D
    {
    public:
        static void init();
        static void shutdown();
        static void beginScene(const OrthographicCamera &camera);
        static void drawQuad(const glm::mat4 &worldMatrix, const glm::vec4 &color = glm::vec4(0.2f, 0.7f, 1.0f, 1.0f));
    };

}
