#pragma once

#include <SolarSystem2D/Simulation/World.hpp>

namespace SolarSystem2D
{

    class IntegrationSystem
    {
    public:
        void update(World& world, float deltaTime);
    };

}