#pragma once

namespace SolarSystem2D 
{

    class Time 
    {
    public:
        static void update();
        static float deltaTime();

    private:
        static float s_deltaTime;
    };

} 
