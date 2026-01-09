#pragma once

#include <SolarSystem2D/Simulation/Systems/GravitySystem.hpp>
#include <SolarSystem2D/Simulation/Systems/IntegrationSystem.hpp>

namespace SolarSystem2D
{
    class Application
    {
    public:
        void run();

    private:
        World m_world;
        GravitySystem m_gravity;
        IntegrationSystem m_integrator;

        static constexpr float FIXED_DT = 0.01f;
    };
}
