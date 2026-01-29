#include "Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace SolarSystem2D 
{

    Transform::Transform() = default;

    void Transform::setParent(Transform* parent)
    {
        m_Parent = parent;
        markDirty();
    }

    void Transform::setPosition(const glm::vec3& position)
    {
        m_Position = position;
        markDirty();
    }

    void Transform::setRotation(float rotation)
    {
        m_Rotation = rotation;
        markDirty();
    }

    void Transform::setScale(const glm::vec3& scale)
    {
        m_Scale = scale;
        markDirty();
    }

    const glm::vec3& Transform::getPosition() const
    {
        return m_Position;
    }

    const glm::vec3& Transform::getScale() const
    {
        return m_Scale;
    }

    void Transform::markDirty()
    {
        m_Dirty = true;
    }

    void Transform::recalcLocalMatrix()
    {
        glm::mat4 mat(1.0f);
        mat = glm::translate(mat, m_Position);
        mat = glm::rotate(mat, m_Rotation, { 0.0f, 0.0f, 1.0f });
        mat = glm::scale(mat, m_Scale);
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
