#include "SolarSystem2D/Math/Vec2.hpp"

namespace SolarSystem2D
{

    Vec2::Vec2(float _x, float _y)
        : x(_x)
        , y(_y)
    {
    }

    Vec2 Vec2::operator+(const Vec2& other) const
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 Vec2::operator-(const Vec2& other) const
    {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 Vec2::operator*(float scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2& Vec2::operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    float Vec2::length() const
    {
        return std::sqrt(x * x + y * y);
    }

    Vec2 Vec2::normalized() const
    {
        float len = length();
        if (len == 0.0f)
            return Vec2(0.0f, 0.0f);
        return Vec2(x / len, y / len);
    }
    
}