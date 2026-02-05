#include "Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace SolarSystem2D
{

    Transform::Transform()
    {
        recalcLocalMatrix();
    }

    void Transform::setParent(Transform* parent)
    {
        if (m_Parent)
        {
            auto& siblings = m_Parent->m_Children;
            siblings.erase(std::remove(siblings.begin(), siblings.end(), this), siblings.end());
        }

        m_Parent = parent;
        if (m_Parent)
            m_Parent->m_Children.push_back(this);

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

    void Transform::markDirty()
    {
        m_Dirty = true;
        for (auto child : m_Children)
            child->markDirty();
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

    void Transform::recalcLocalMatrix()
    {
        glm::mat4 T = glm::translate(glm::mat4(1.0f), m_Position);
        glm::mat4 R = glm::rotate(glm::mat4(1.0f), m_Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 S = glm::scale(glm::mat4(1.0f), m_Scale);

        m_LocalMatrix = T * R * S;
    }

}
