#include "Renderer2D.hpp"

#include "VertexArray.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"

#include <glad/glad.h>
#include <memory>

namespace SolarSystem2D
{

    static std::shared_ptr<VertexArray> s_VAO;
    static std::shared_ptr<Shader> s_Shader;

    void Renderer2D::init()
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        uint32_t indices[] = {0, 1, 2};

        s_VAO = std::make_shared<VertexArray>();

        auto vb = std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
        auto ib = std::make_shared<IndexBuffer>(indices, 3);

        s_VAO->setVertexBuffer(vb);
        s_VAO->setIndexBuffer(ib);

        const std::string vertexSrc = R"(
                #version 330 core

                layout(location = 0) in vec3 aPos;

                void main()
                {
                    gl_Position = vec4(aPos, 1.0);
                }
            )";

        const std::string fragmentSrc = R"(
                #version 330 core

                out vec4 FragColor;

                void main()
                {
                    FragColor = vec4(1.0, 0.4, 0.2, 1.0);
                }
            )";

        s_Shader = std::make_shared<Shader>(vertexSrc, fragmentSrc);
    }

    void Renderer2D::drawTriangle()
    {
        s_Shader->bind();
        s_VAO->bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
    }

}
