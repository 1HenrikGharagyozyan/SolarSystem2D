#include "Time.hpp"

#include <chrono>

namespace SolarSystem2D 
{

    static auto s_lastTime = std::chrono::high_resolution_clock::now();
    float Time::s_deltaTime = 0.0f;

    void Time::update()
    {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> delta = now - s_lastTime;
        s_deltaTime = delta.count();
        s_lastTime = now;
    }

    float Time::deltaTime()
    {
        return s_deltaTime;
    }

} 
