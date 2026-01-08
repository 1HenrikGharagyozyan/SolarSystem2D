#include "SolarSystem2D/Core/Application.hpp"
#include <iostream>

namespace SolarSystem2D 
{

    void Application::run()
    {
        auto sun = m_World.createEntity();
        auto& transform = m_World.addTransform(sun);

        transform.x = 0.0f;
        transform.y = 0.0f;

        std::cout << "World initialized with " 
                  << m_World.entities().size() 
                  << " entity(ies)." << "\n";
    }

} // namespace SolarSystem2D