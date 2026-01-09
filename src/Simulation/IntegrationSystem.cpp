#include <SolarSystem2D/Simulation/Systems/IntegrationSystem.hpp>

namespace SolarSystem2D
{

    void IntegrationSystem::update(World& world, float dt)
    {
        auto entities = world.entities();

        for (EntityID id : entities)
        {
            auto& transform = world.transform(id);
            auto& body = world.rigidBody(id);
            auto& accel = world.acceleration(id);

            // v = v + a * dt
            body.velocity += accel.value * dt;

            // x = x + v * dt
            transform.x += body.velocity.x * dt;
            transform.y += body.velocity.y * dt;
        }
    }
    
}
