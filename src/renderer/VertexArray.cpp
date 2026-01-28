#include "VertexArray.hpp"

#include "Buffer.hpp"
#include <glad/glad.h>


namespace SolarSystem2D
{

    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_RendererID);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void VertexArray::bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::unbind() const
    {
        glBindVertexArray(0);
    }
    
    void VertexArray::setVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
    {
        bind();
        vertexBuffer->bind();

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*)0);
        m_VertexBuffer = vertexBuffer;
    }

    void VertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
    {
        bind();
        indexBuffer->bind();
        m_IndexBuffer = indexBuffer;
    }

    const std::shared_ptr<VertexBuffer>& VertexArray::getVertexBuffer() const
    {
        return m_VertexBuffer;
    }

    const std::shared_ptr<IndexBuffer>& VertexArray::getIndexBuffer() const
    {
        return m_IndexBuffer;
    }

}