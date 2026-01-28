#include "OrthographicCamera.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace SolarSystem2D 
{

    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
    {
        m_Projection = glm::ortho(left, right, bottom, top);
        m_View = glm::mat4(1.0f);
        m_ViewProjection = m_Projection * m_View;
    }

    const glm::mat4& OrthographicCamera::getProjection() const
    {
        return m_Projection;
    }

    const glm::mat4& OrthographicCamera::getViewProjection() const
    {
        return m_ViewProjection;
    }

} 
