#pragma once

#include <glm/glm.hpp>

namespace SolarSystem2D 
{

    struct Transform 
    {
        glm::vec3 position { 0.0f };
        glm::vec3 scale { 1.0f };
        float rotation = 0.0f; // radians

        glm::mat4 getMatrix() const;
    };

}
