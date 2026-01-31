#include "scene/Planet.hpp"

namespace SolarSystem2D
{

    Planet::Planet(Entity& entity, float size)
    {
        entity.getTransform().setScale({ size, size, 1.0f });
    }

}
