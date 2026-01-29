#pragma once

#include <glm/glm.hpp>

#include <vector>

namespace SolarSystem2D 
{

    class Transform 
    {
    public:
        Transform();

        void setParent(Transform* parent);
        const glm::mat4& getWorldMatrix();

        glm::vec3 position{ 0.0f };
        float rotation{ 0.0f }; // in radians
        glm::vec3 scale{ 1.0f };

    private:
        void recalcLocalMatrix();

    private:
        glm::mat4 m_LocalMatrix{ 1.0f };
        glm::mat4 m_WorldMatrix{ 1.0f };

        Transform* m_Parent = nullptr;
        bool m_Dirty = true;
    };

}
