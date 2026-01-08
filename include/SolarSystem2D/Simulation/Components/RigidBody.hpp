#pragma once
#include <SolarSystem2D/Math/Vec2.hpp>

namespace SolarSystem2D
{

    struct RigidBody
    {
        Vec2 velocity{ 0.0f, 0.0f };
        float mass = 1.0f;
    };
}