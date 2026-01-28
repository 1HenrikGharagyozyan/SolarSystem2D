#pragma once

#include <memory>

namespace SolarSystem2D
{

    class VertexBuffer;
    class IndexBuffer;
    
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void bind() const;
        void unbind() const;

        void setVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
        void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

        const std::shared_ptr<VertexBuffer>& getVertexBuffer() const;
        const std::shared_ptr<IndexBuffer>& getIndexBuffer() const;

    private:
        uint32_t m_RendererID;
        std::shared_ptr<VertexBuffer> m_VertexBuffer;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    };

}