#include "Shader.hpp"

#include <glad/glad.h>
#include <stdexcept>

namespace SolarSystem2D
{

    static uint32_t compileShader(uint32_t type, const std::string& src)
    {
        uint32_t id = glCreateShader(type);
        const char* source = src.c_str();
        glShaderSource(id, 1, &source, nullptr);
        glCompileShader(id);

        int success;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char info[32];
            glGetShaderInfoLog(id, 512, nullptr, info);
            throw std::runtime_error(info);
        }
        return id;
    }

    Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        uint32_t program = glCreateProgram();
        uint32_t vs = compileShader(GL_VERTEX_SHADER, vertexSrc);
        uint32_t fs = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);

        m_RendererID = program;
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_RendererID);
    }

    void Shader::bind() const
    {
        glUseProgram(m_RendererID);
    }

    void Shader::unbind() const
    {
        glUseProgram(0);
    }
}