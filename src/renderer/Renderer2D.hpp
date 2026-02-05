#pragma once

#include "OrthographicCamera.hpp"
#include <glm/glm.hpp>

namespace SolarSystem2D
{
    class Renderer2D
    {
    public:
        static void init();
        static void shutdown();

        static void beginScene(const OrthographicCamera &camera);
        static void endScene();

        static void drawQuad(const glm::mat4 &transform, const glm::vec4 &color = {0.2f,0.7f,1.0f,1.0f});
    private:
        static glm::mat4 s_ViewProjection;
    };
}
