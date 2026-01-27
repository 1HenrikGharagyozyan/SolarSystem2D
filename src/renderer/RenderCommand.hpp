#pragma once

namespace SolarSystem2D 
{

    class RenderCommand 
    {
    public:
        static void init();
        static void setClearColor(float r, float g, float b, float a);
        static void clear();
    };

} 
