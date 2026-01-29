#pragma once

#include "core/Transform.hpp"

namespace SolarSystem2D
{

    class Planet
    {
    public:
        Planet(float orbitRadius, float orbitSpeed, float size);

        void update(float deltaTime);
        const Transform& getTransform() const;

    private:
        float m_OrbitRadius;
        float m_OrbitSpeed; // radians per second
        float m_Angle; // current angle in orbit

        Transform m_Transform;
    };

}