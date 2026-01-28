#pragma once

#include <cstdint>

namespace SolarSystem2D
{

    class VertexBuffer
    {
    public:
        VertexBuffer(const void* data, uint32_t size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

    private:
        uint32_t m_RendererID;
    };


    class IndexBuffer
    {
    public:
        IndexBuffer(const void* data, uint32_t count);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };

}