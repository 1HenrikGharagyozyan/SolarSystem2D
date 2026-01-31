#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace SolarSystem2D
{

    class Transform
    {
    public:
        Transform() = default;

        void setParent(Transform* parent);

        void setPosition(const glm::vec3& position);
        void setRotation(float rotation);
        void setScale(const glm::vec3& scale);

        const glm::vec3& getPosition() const { return m_Position; }
        const glm::vec3& getScale() const { return m_Scale; }

        const glm::mat4& getWorldMatrix();

    private:
        void recalcLocalMatrix();
        void recalcWorldMatrix();
        void markDirty();

    private:
        glm::vec3 m_Position { 0.0f };
        float m_Rotation = 0.0f;
        glm::vec3 m_Scale { 1.0f };

        glm::mat4 m_LocalMatrix { 1.0f };
        glm::mat4 m_WorldMatrix { 1.0f };

        Transform* m_Parent = nullptr;
        std::vector<Transform*> m_Children;

        bool m_Dirty = true;
    };

} 
