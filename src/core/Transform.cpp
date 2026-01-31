#include "Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

namespace SolarSystem2D
{

    void Transform::setParent(Transform* parent)
    {
        if (m_Parent == parent)
            return;

        if (m_Parent)
        {
            auto& siblings = m_Parent->m_Children;
            siblings.erase(
                std::remove(siblings.begin(), siblings.end(), this),
                siblings.end()
            );
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
        if (!m_Dirty)
        {
            m_Dirty = true;
            for (Transform* child : m_Children)
                child->markDirty();
        }
    }

    const glm::mat4& Transform::getWorldMatrix()
    {
        if (m_Dirty)
        {
            recalcLocalMatrix();
            recalcWorldMatrix();
            m_Dirty = false;
        }

        return m_WorldMatrix;
    }

    void Transform::recalcLocalMatrix()
    {
        glm::mat4 m(1.0f);

        m = glm::translate(m, m_Position);
        m = glm::rotate(m, m_Rotation, glm::vec3(0, 0, 1));
        m = glm::scale(m, m_Scale);

        m_LocalMatrix = m;
    }

    void Transform::recalcWorldMatrix()
    {
        if (m_Parent)
            m_WorldMatrix = m_Parent->getWorldMatrix() * m_LocalMatrix;
        else
            m_WorldMatrix = m_LocalMatrix;
    }

}
