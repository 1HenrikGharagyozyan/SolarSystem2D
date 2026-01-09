#include <SolarSystem2D/Simulation/Systems/GravitySystem.hpp>
#include <SolarSystem2D/Math/Vec2.hpp>

#include <cmath>

namespace SolarSystem2D
{
    static constexpr float G = 1.0f; // нормализованная гравитационная константа

    void GravitySystem::update(World& world)
    {
        auto entities = world.entities();

        // 1. Сброс ускорений
        for (EntityID id : entities)
        {
            world.acceleration(id).value = { 0.0f, 0.0f };
        }

        // 2. Попарная гравитация
        for (size_t i = 0; i < entities.size(); ++i)
        {
            for (size_t j = i + 1; j < entities.size(); ++j)
            {
                EntityID a = entities[i];
                EntityID b = entities[j];

                auto& ta = world.transform(a);
                auto& tb = world.transform(b);

                auto& ra = world.rigidBody(a);
                auto& rb = world.rigidBody(b);

                Vec2 direction {
                    tb.x - ta.x,
                    tb.y - ta.y
                };

                float distance = direction.length();
                if (distance < 0.0001f)
                    continue;

                Vec2 forceDir = direction.normalized();

                float force =
                    G * ra.mass * rb.mass / (distance * distance);

                Vec2 accelA = forceDir * (force / ra.mass);
                Vec2 accelB = forceDir * (-force / rb.mass);

                world.acceleration(a).value += accelA;
                world.acceleration(b).value += accelB;
            }
        }
    }
}
