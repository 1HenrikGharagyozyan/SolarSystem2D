#pragma once
#include "SolarSystem2D/Simulation/Entity.hpp"
#include "SolarSystem2D/Simulation/Components/Transform2D.hpp"

#include <vector>

namespace SolarSystem2D
{

    class World
    {
    public:
        EntityID createEntity();
        Transform2D& addTransform(EntityID id);

        const std::vector<EntityID>& entities() const { return m_Entities; }

    private:
        std::vector<EntityID> m_Entities;
        std::vector<Transform2D> m_Transforms;
    };
}