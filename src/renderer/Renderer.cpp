#include "Renderer.hpp"
#include "RenderCommand.hpp"

namespace SolarSystem2D
{

    void Renderer::init()
    {
        RenderCommand::init();
    }

    void Renderer::beginFrame()
    {
        RenderCommand::setClearColor(0.05f, 0.05f, 0.1f, 1.0f);
        RenderCommand::clear();
    }

    void Renderer::endFrame()
    {
    }

} 
