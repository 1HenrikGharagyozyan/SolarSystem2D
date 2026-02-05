#pragma once
#include "core/Transform.hpp"
#include <string>

namespace SolarSystem2D
{

    class Entity
    {
    public:
        explicit Entity(std::string name);

        Transform& getTransform();
        const std::string& getName() const;

    private:
        std::string m_Name;
        Transform m_Transform;
    };

}
