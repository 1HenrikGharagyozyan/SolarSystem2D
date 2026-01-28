#pragma once

#include <string>
#include <cstdint>

#include <glm/glm.hpp>

namespace SolarSystem2D
{

    class Shader
    {
    public:
        Shader(const std::string &vertexSrc, const std::string &fragmentSrc);
        ~Shader();

        void bind() const;
        void unbind() const;

        void setMat4(const std::string &name, const glm::mat4 &matrix);
        void setFloat4(const std::string &name, const glm::vec4 &value);

        uint32_t getRendererID() const { return m_RendererID; }

    private:
        uint32_t m_RendererID;

        int getUniformLocation(const std::string &name);
    };

}