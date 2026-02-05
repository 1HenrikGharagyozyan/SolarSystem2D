#include "Planet.hpp"
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
        if (m_OrbitSpeed > 0.0f)
            m_Angle += m_OrbitSpeed * dt;

        // Orbit position calculation
        glm::vec3 orbitPos;
        orbitPos.x = cos(m_Angle) * m_OrbitRadius;
        orbitPos.y = sin(m_Angle) * m_OrbitRadius;
        orbitPos.z = 0.0f;
        m_OrbitEntity.getTransform().setPosition(orbitPos);

        // Visual entity is positioned at the center of the orbit entity, so we set it to (0,0) relative to the orbit entity
        m_VisualEntity.getTransform().setPosition(glm::vec3(0.0f));

        // Rotation around its own axis (e.g. day/night cycle)
        // float rotationSpeed = 1.0f;
        // m_VisualEntity.getTransform().setRotation(m_VisualEntity.getTransform().getRotation() + rotationSpeed * dt);
    }


}
