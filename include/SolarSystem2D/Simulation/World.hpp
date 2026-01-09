#pragma once
#include "SolarSystem2D/Simulation/Entity.hpp"
#include <SolarSystem2D/Simulation/Components/Acceleration.hpp>
#include "SolarSystem2D/Simulation/Components/Transform2D.hpp"
#include "SolarSystem2D/Simulation/Components/RigidBody.hpp"

#include <vector>

namespace SolarSystem2D
{

    class World
    {
    public:
        EntityID createEntity();

        Acceleration& addAcceleration(EntityID id);
        Transform2D& addTransform(EntityID id);
        RigidBody& addRigidBody(EntityID id);

        Acceleration& acceleration(EntityID id);
        Transform2D& transform(EntityID id);
        RigidBody& rigidBody(EntityID id);

        std::vector<EntityID> entities() const;
    
    private:
        std::vector<Acceleration> m_Accelerations;
        std::vector<Transform2D> m_Transforms;
        std::vector<RigidBody> m_RigidBodies;
    };

}