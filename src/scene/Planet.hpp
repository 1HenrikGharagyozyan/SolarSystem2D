#pragma once

#include "scene/Entity.hpp"

namespace SolarSystem2D
{

    class Planet
    {
    public:
        // Visual component: sets scale only. Orbit class controls position.
        Planet(Entity& entity, float size);

    private:
        Entity& m_Entity;
    };

} 
