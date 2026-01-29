#include "Planet.hpp"

#include <cmath>

namespace SolarSystem2D
{

    Planet::Planet(float orbitRadius, float orbitSpeed, float size)
        : m_OrbitRadius(orbitRadius)
        , m_OrbitSpeed(orbitSpeed)
        , m_Angle(0.0f)
    {
        m_Transform.scale = { size, size, 1.0f };
    }

    void Planet::update(float deltaTime)
    {
        m_Angle += m_OrbitSpeed * deltaTime;

        float x = m_OrbitRadius * std::cos(m_Angle);
        float y = m_OrbitRadius * std::sin(m_Angle);
        m_Transform.position = { x, y, 0.0f };

    }

    const Transform &Planet::getTransform() const
    {
        return m_Transform;
    }

}