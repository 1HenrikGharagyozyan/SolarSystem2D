#include "Renderer2D.hpp"

#include "VertexArray.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"

#include <glm/glm.hpp>
#include <glad/glad.h>

#include <memory>

namespace SolarSystem2D 
{

    static std::shared_ptr<VertexArray> s_QuadVAO;
    static std::shared_ptr<Shader> s_Shader;
    static glm::mat4 s_ViewProjection;

    void Renderer2D::init()
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
        };

        uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };

        s_QuadVAO = std::make_shared<VertexArray>();
        auto vb = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
        auto ib = std::make_shared<IndexBuffer>(indices, 6);

        s_QuadVAO->setVertexBuffer(vb);
        s_QuadVAO->setIndexBuffer(ib);

        const std::string vertexSrc = R"(
                #version 330 core

                layout(location = 0) in vec3 aPos;

                uniform mat4 u_ViewProjection;
                uniform mat4 u_Transform;

                void main()
                {
                    gl_Position = u_ViewProjection * u_Transform * vec4(aPos, 1.0);
                }
            )";

        const std::string fragmentSrc = R"(
                #version 330 core

                out vec4 FragColor;

                void main()
                {
                    FragColor = vec4(0.2, 0.7, 1.0, 1.0);
                }
            )";

        s_Shader = std::make_shared<Shader>(vertexSrc, fragmentSrc);
    }

    void Renderer2D::beginScene(const OrthographicCamera& camera)
    {
        s_ViewProjection = camera.getViewProjection();
        s_Shader->setMat4("u_ViewProjection", s_ViewProjection);
    }

    void Renderer2D::drawQuad(const Transform& transform)
    {
        s_Shader->setMat4("u_Transform", transform.getMatrix());
        s_Shader->bind();
        s_QuadVAO->bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }

} 
