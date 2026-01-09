#include <SolarSystem2D/Core/Application.hpp>
#include <iostream>

namespace SolarSystem2D
{
    void Application::run()
    {
        EntityID sun = m_world.createEntity();
        EntityID planet = m_world.createEntity();

        m_world.addTransform(sun);
        m_world.addRigidBody(sun);
        m_world.addAcceleration(sun);

        m_world.addTransform(planet);
        m_world.addRigidBody(planet);
        m_world.addAcceleration(planet);

        m_world.transform(planet).x = 10.0f;

        m_world.rigidBody(sun).mass = 1000.0f;
        m_world.rigidBody(planet).mass = 1.0f;

        // Start velocity for a circular orbit
        m_world.rigidBody(planet).velocity = { 0.0f, 6.0f };

        // Simulation
        for (int step = 0; step < 5000; ++step)
        {
            m_gravity.update(m_world);
            m_integrator.update(m_world, FIXED_DT);

            auto& p = m_world.transform(planet);
            std::cout << p.x << " " << p.y << "\n";
        }
    }
}
