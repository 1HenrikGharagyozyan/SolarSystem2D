#pragma once

namespace SolarSystem2D
{
    
    class Time
    {
    public:
        static float GetDeltaTime();
        static void Update();
        
    private:
        static float s_DeltaTime;
    };

} 
    