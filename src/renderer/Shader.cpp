#include "Shader.hpp"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <unordered_map>

namespace SolarSystem2D
{

    static unsigned int compileShader(unsigned int type, const std::string &source)
    {
        unsigned int id = glCreateShader(type);
        const char *src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int success;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char infoLog[1024];
            glGetShaderInfoLog(id, 1024, nullptr, infoLog);
            // In the real project there will be logger/assert
        }

        return id;
    }

    Shader::Shader(const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        unsigned int program = glCreateProgram();
        unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexSrc);
        unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

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

    int Shader::getUniformLocation(const std::string &name)
    {
        return glGetUniformLocation(m_RendererID, name.c_str());
    }

    void Shader::setMat4(const std::string &name, const glm::mat4 &matrix)
    {
        bind();
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void Shader::setFloat4(const std::string &name, const glm::vec4 &value)
    {
        bind();
        glUniform4f(getUniformLocation(name), value.x, value.y, value.z, value.w);
    }

}
