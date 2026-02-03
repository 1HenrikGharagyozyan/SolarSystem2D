#include "DebugRenderer2D.hpp"

#include "OrthographicCamera.hpp"
#include "Shader.hpp"

#include <glad/glad.h>

#include <memory>
#include <vector>
#include <cmath>

namespace SolarSystem2D
{
    static std::shared_ptr<Shader> s_Shader;
    static glm::mat4 s_ViewProjection;

    void DebugRenderer2D::init()
    {
        const std::string vertexSrc = R"(
                #version 330 core

                layout(location = 0) in vec2 aPos;

                uniform mat4 u_ViewProjection;

                void main()
                {
                    gl_Position = u_ViewProjection * vec4(aPos, 0.0, 1.0);
                }
            )";

        const std::string fragmentSrc = R"(
                #version 330 core

                out vec4 FragColor;

                uniform vec4 u_Color;
                
                void main()
                {
                    FragColor = u_Color;
                }
            )";

        s_Shader = std::make_shared<Shader>(vertexSrc, fragmentSrc);
    }

    void DebugRenderer2D::shutdown()
    {
        s_Shader.reset();
    }

    void DebugRenderer2D::beginScene(const OrthographicCamera& camera)
    {
        s_ViewProjection = camera.getViewProjection();
        s_Shader->bind();
        s_Shader->setMat4("u_ViewProjection", s_ViewProjection);
    }

    void DebugRenderer2D::endScene()
    {
        s_Shader->unbind();
    }

    void DebugRenderer2D::drawCircle(const glm::vec2& center, float radius, const glm::vec4& color, int segments)
    {
        std::vector<glm::vec2> vertices;
        vertices.reserve(segments + 1);

        for (int i = 0; i <= segments; ++i)
        {
            float angle = (float)i / segments * 2.0f * 3.1415926f;
            vertices.emplace_back(
                center.x + std::cos(angle) * radius,
                center.y + std::sin(angle) * radius
            );
        }

        GLuint vao, vbo;
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER,
                     vertices.size() * sizeof(glm::vec2),
                     vertices.data(),
                     GL_DYNAMIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), nullptr);

        s_Shader->setFloat4("u_Color", color);
        glDrawArrays(GL_LINE_STRIP, 0, (GLsizei)vertices.size());

        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }
}

