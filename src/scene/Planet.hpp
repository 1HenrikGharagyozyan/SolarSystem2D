#pragma once

#include "Entity.hpp"

namespace SolarSystem2D
{

    class Planet
    {
    public:
        Planet(Entity& entity, float orbitRadius, float orbitSpeed, float size);

        void update(float deltaTime);

    private:
        Entity& m_Entity;

        float m_OrbitRadius;
        float m_OrbitSpeed; // radians per second
        float m_Angle = 0.0f; // current angle in orbit
    };

}