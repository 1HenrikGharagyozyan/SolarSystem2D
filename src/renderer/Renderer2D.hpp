#pragma once

#include "OrthographicCamera.hpp"

namespace SolarSystem2D 
{

    class Renderer2D 
    {
    public:
        static void init();
        static void beginScene(const OrthographicCamera& camera);
        static void drawQuad();
    };

} 
