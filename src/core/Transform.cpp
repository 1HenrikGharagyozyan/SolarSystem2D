#include "Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace SolarSystem2D 
{

    Transform::Transform() = default;

    void Transform::setParent(Transform* parent)
    {
        m_Parent = parent;
        m_Dirty = true;
    }

    void Transform::recalcLocalMatrix()
    {
        glm::mat4 mat(1.0f);
        mat = glm::translate(mat, position);
        mat = glm::rotate(mat, rotation, { 0.0f, 0.0f, 1.0f });
        mat = glm::scale(mat, scale);
        m_LocalMatrix = mat;
    }

    const glm::mat4& Transform::getWorldMatrix() 
    {
        if (m_Dirty)
        {
            recalcLocalMatrix();

            if (m_Parent)
                m_WorldMatrix = m_Parent->getWorldMatrix() * m_LocalMatrix;
            else
                m_WorldMatrix = m_LocalMatrix;

            m_Dirty = false;
        }

        return m_WorldMatrix;
    }

}
