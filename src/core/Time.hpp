#pragma once

namespace SolarSystem2D 
{

    class Time 
    {
    public:
        static void update();
        static float getDeltaTime();

    private:
        static float s_deltaTime;
    };

} 
