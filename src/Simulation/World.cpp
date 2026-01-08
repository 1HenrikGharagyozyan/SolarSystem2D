#include "SolarSystem2D/Simulation/World.hpp"

namespace SolarSystem2D
{
    EntityID World::createEntity()
    {
        EntityID id = static_cast<EntityID>(m_Entities.size());
        m_Entities.push_back(id);
        return id;
    }

    Transform2D& World::addTransform(EntityID id)
    {
        m_Transforms.emplace_back();
        return m_Transforms.back();
    }

}