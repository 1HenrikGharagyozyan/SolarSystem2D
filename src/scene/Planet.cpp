#include "scene/Planet.hpp"
#include <cmath>

namespace SolarSystem2D 
{

    Planet::Planet(Entity& entity, float orbitRadius, float orbitSpeed, float size)
        : m_Entity(entity)
        , m_OrbitRadius(orbitRadius)
        , m_OrbitSpeed(orbitSpeed)
    {
        m_Entity.getTransform().setScale({ size, size, 1.0f });
    }

    void Planet::update(float deltaTime)
    {
        m_Angle += m_OrbitSpeed * deltaTime;

        m_Entity.getTransform().setPosition({
            std::cos(m_Angle) * m_OrbitRadius,
            std::sin(m_Angle) * m_OrbitRadius,
            0.0f
        });
    }

} 
