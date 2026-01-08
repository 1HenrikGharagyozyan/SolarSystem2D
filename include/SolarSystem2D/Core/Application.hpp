#pragma once
#include "SolarSystem2D/Simulation/World.hpp"

namespace SolarSystem2D 
{

    class Application
    {
    public: 
        void run();
    
    private:
        World m_World;
    };

}