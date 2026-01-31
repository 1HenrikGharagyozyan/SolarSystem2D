#pragma once

#include "Entity.hpp"

namespace SolarSystem2D
{

    class Orbit
    {
    public:
        Orbit(Entity& entity, float radius, float speed);

        void update(float dt);

    private:
        Entity& m_Entity;
        float m_Radius;
        float m_Speed;
        float m_Angle = 0.0f;
    };

}
