#pragma once
#include <math.h>

namespace SolarSystem2D
{

    struct Vec2
    {
        float x = 0.0f;
        float y = 0.0f;

        Vec2() = default;
        Vec2(float _x, float _y);

        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        Vec2 operator*(float scalar) const;

        Vec2& operator+=(const Vec2& other);

        float length() const;
        Vec2 normalized() const;
    };
}