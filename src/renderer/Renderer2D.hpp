#pragma once

#include "OrthographicCamera.hpp"
#include "core/Transform.hpp"

namespace SolarSystem2D 
{

    class Renderer2D 
    {
    public:
        static void init();
        static void beginScene(const OrthographicCamera& camera);
        static void drawQuad(const glm::mat4& worldMatrix);
    };

}
