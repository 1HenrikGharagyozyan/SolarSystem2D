#include "Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

namespace SolarSystem2D
{

    void Transform::setParent(Transform *parent)
    {
        if (m_Parent == parent)
            return;

        if (m_Parent)
        {
            auto &siblings = m_Parent->m_Children;
            siblings.erase(
                std::remove(siblings.begin(), siblings.end(), this),
                siblings.end());
        }

        m_Parent = parent;

        if (m_Parent)
            m_Parent->m_Children.push_back(this);

        markDirty();
    }

    void Transform::setPosition(const glm::vec3 &position)
    {
        m_Position = position;
        markDirty();
    }

    void Transform::setRotation(float rotation)
    {
        m_Rotation = rotation;
        markDirty();
    }

    void Transform::setScale(const glm::vec3 &scale)
    {
        m_Scale = scale;
        markDirty();
    }

    void Transform::markDirty()
    {
        if (!m_Dirty)
        {
            m_Dirty = true;
            for (Transform *child : m_Children)
                child->markDirty();
        }
    }

    const glm::mat4 &Transform::getWorldMatrix()
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

        // ✔️ TRANSLATION FIRST — ORBIT RADIUS
        m = glm::translate(m, m_Position);

        // ✔️ ROTATION (optional, future-proof)
        m = glm::rotate(m, m_Rotation, glm::vec3(0, 0, 1));

        // ✔️ SCALE LAST — SIZE ONLY
        m = glm::scale(m, m_Scale);

        m_LocalMatrix = m;
    }

    void Transform::recalcWorldMatrix()
    {
        if (m_Parent)
        {
            // Compose world matrix from parent but ignore parent's scale so that
            // children's translations (e.g. orbital radii) are not scaled by parent.
            glm::mat4 parentWorld = m_Parent->getWorldMatrix();

            // Normalize basis vectors (remove scale), preserve rotation and translation
            glm::vec3 xAxis = glm::vec3(parentWorld[0]);
            glm::vec3 yAxis = glm::vec3(parentWorld[1]);
            glm::vec3 zAxis = glm::vec3(parentWorld[2]);

            float sx = glm::length(xAxis);
            float sy = glm::length(yAxis);
            float sz = glm::length(zAxis);

            if (sx != 0.0f)
                parentWorld[0] /= sx;
            if (sy != 0.0f)
                parentWorld[1] /= sy;
            if (sz != 0.0f)
                parentWorld[2] /= sz;

            m_WorldMatrix = parentWorld * m_LocalMatrix;
        }
        else
            m_WorldMatrix = m_LocalMatrix;
    }

} 
