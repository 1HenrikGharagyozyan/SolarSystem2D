#pragma once

#include "scene/Entity.hpp"

namespace SolarSystem2D
{

    class Planet
    {
    public:
        // orbitEntity — позиция на орбите; visualEntity — масштаб. Для Солнца передать одну сущность дважды.
        Planet(Entity& orbitEntity, Entity& visualEntity, float orbitRadius, float orbitSpeed, float size);
        void update(float dt);

    private:
        Entity& m_OrbitEntity;
        Entity& m_VisualEntity;
        float m_OrbitRadius;
        float m_OrbitSpeed;
        float m_Angle = 0.0f;
        float m_Size;
    };

} 
