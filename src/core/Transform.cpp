#include "Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace SolarSystem2D 
{

    glm::mat4 Transform::getMatrix() const
    {
        glm::mat4 mat(1.0f);
        mat = glm::translate(mat, position);
        mat = glm::rotate(mat, rotation, { 0.0f, 0.0f, 1.0f });
        mat = glm::scale(mat, scale);
        return mat;
    }

} 
