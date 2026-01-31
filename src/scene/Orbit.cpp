#include "scene/Orbit.hpp"
#include <glm/glm.hpp>
#include <cmath>

namespace SolarSystem2D
{

    Orbit::Orbit(Entity& entity, float radius, float speed)
        : m_Entity(entity)
        , m_Radius(radius)
        , m_Speed(speed)
    {
    }

    void Orbit::update(float dt)
    {
        m_Angle += m_Speed * dt;

        glm::vec3 pos(
            std::cos(m_Angle) * m_Radius,
            std::sin(m_Angle) * m_Radius,
            0.0f
        );

        m_Entity.getTransform().setPosition(pos);
    }

}
