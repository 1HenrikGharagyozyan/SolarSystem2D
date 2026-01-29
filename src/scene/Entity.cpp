#include "Entity.hpp"

namespace SolarSystem2D 
{

    Entity::Entity(std::string name)
        : m_Name(std::move(name))
    {
    }

    Transform& Entity::getTransform()
    {
        return m_Transform;
    }

    const std::string& Entity::getName() const
    {
        return m_Name;
    }

} 
