#pragma once

#include <string>
#include <cstdint>

namespace SolarSystem2D
{

    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();

        void bind() const;
        void unbind() const;

        const uint32_t getID() const { return m_RendererID; } 

    private:
        uint32_t m_RendererID;
    };

}