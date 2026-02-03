#include "scene/Planet.hpp"

#include "core/Transform.hpp"

#include <glm/glm.hpp>
#include <cmath>

namespace SolarSystem2D
{

    Planet::Planet(Entity& orbitEntity, Entity& visualEntity, float orbitRadius, float orbitSpeed, float size)
        : m_OrbitEntity(orbitEntity)
        , m_VisualEntity(visualEntity)
        , m_OrbitRadius(orbitRadius)
        , m_OrbitSpeed(orbitSpeed)
        , m_Size(size)
    {
        m_VisualEntity.getTransform().setScale({size, size, 1.0f});
    }

    void Planet::update(float dt)
    {
        m_Angle += m_OrbitSpeed * dt;

        glm::vec3 localPosition{
            std::cos(m_Angle) * m_OrbitRadius,
            std::sin(m_Angle) * m_OrbitRadius,
            0.0f
        };

        m_OrbitEntity.getTransform().setPosition(localPosition);
    }

} 