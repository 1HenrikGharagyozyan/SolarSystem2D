#include "Planet.hpp"

#include <cmath>

namespace SolarSystem2D
{

    Planet::Planet(Entity& entity, float orbitRadius, float orbitSpeed, float size)
        : m_Entity(entity)
        , m_OrbitRadius(orbitRadius)
        , m_OrbitSpeed(orbitSpeed)
        , m_Angle(0.0f)
    {
        m_Entity.getTransform().scale = { size, size, 1.0f };
    }

    void Planet::update(float deltaTime)
    {
        m_Angle += m_OrbitSpeed * deltaTime;

        auto& t = m_Entity.getTransform();
        t.position.x = m_OrbitRadius * std::cos(m_Angle);
        t.position.y = m_OrbitRadius * std::sin(m_Angle);
    }

}