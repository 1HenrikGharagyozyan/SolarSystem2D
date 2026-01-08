#include <SolarSystem2D/Core/Application.hpp>
#include <iostream>

namespace SolarSystem2D
{

    void Application::run()
    {
        EntityID sun = m_World.createEntity();

        auto& transform = m_World.addTransform(sun);
        auto& body = m_World.addRigidBody(sun);

        transform.x = 0.0f;
        transform.y = 0.0f;

        body.mass = 1000.0f;
        body.velocity = { 0.0f, 0.0f };

        std::cout << "Sun created with mass = "
                  << body.mass << "\n";
    }

}
