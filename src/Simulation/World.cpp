#include <SolarSystem2D/Simulation/World.hpp>

namespace SolarSystem2D
{
    EntityID World::createEntity()
    {
        return static_cast<EntityID>(m_Transforms.size());
    }

    Acceleration& World::addAcceleration(EntityID)
    {
        m_Accelerations.emplace_back();
        return m_Accelerations.back();
    }

    Transform2D& World::addTransform(EntityID)
    {
        m_Transforms.emplace_back();
        return m_Transforms.back();
    }

    RigidBody& World::addRigidBody(EntityID)
    {
        m_RigidBodies.emplace_back();
        return m_RigidBodies.back();
    }


    Acceleration& World::acceleration(EntityID id)
    {
        return m_Accelerations[id];
    }

    Transform2D& World::transform(EntityID id)
    {
        return m_Transforms[id];
    }

    RigidBody& World::rigidBody(EntityID id)
    {
        return m_RigidBodies[id];
    }

    std::vector<EntityID> World::entities() const
    {
        std::vector<EntityID> result;
        for (EntityID i = 0; i < m_Transforms.size(); ++i)
            result.push_back(i);
        return result;
    }
}
