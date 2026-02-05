#pragma once

#include "scene/Entity.hpp"

namespace SolarSystem2D
{

    class Planet
    {
    public:
        Planet(Entity& orbitEntity, Entity& visualEntity, float orbitRadius, float orbitSpeed, float size);

        void update(float dt);

    private:
        Entity& m_OrbitEntity;
        Entity& m_VisualEntity;

        float m_OrbitRadius;
        float m_OrbitSpeed;
        float m_Size;
        float m_Angle = 0.0f;
    };

}
