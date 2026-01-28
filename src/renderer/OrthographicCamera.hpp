#pragma once

#include <glm/glm.hpp>

namespace SolarSystem2D
{

    class OrthographicCamera
    {
    public:
        OrthographicCamera(float left, float right, float bottom, float top);

        const glm::mat4& getProjection() const;
        const glm::mat4& getViewProjection() const;

    private:
        glm::mat4 m_Projection;
        glm::mat4 m_View;
        glm::mat4 m_ViewProjection;
    };

}