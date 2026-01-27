#include "RenderCommand.hpp"

#include <glad/glad.h>

namespace SolarSystem2D 
{

    void RenderCommand::init()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void RenderCommand::setClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void RenderCommand::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

} 
