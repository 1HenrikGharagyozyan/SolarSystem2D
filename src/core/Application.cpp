#include "Application.hpp"
#include "scene/Scene.hpp"
#include "core/Window.hpp"
#include "core/Time.hpp"
#include "renderer/Renderer2D.hpp"
#include "renderer/DebugRenderer2D.hpp"
#include "renderer/RenderCommand.hpp"

namespace SolarSystem2D
{

    Application::Application()
    {
        m_Window = std::make_unique<Window>(1280, 720, "SolarSystem2D");

        Renderer2D::init();
        DebugRenderer2D::init();

        m_Camera = std::make_unique<OrthographicCamera>(-1.6f, 1.6f, -0.9f, 0.9f);

        m_Scene = std::make_unique<Scene>();
    }

    Application::~Application()
    {
        DebugRenderer2D::shutdown();
        Renderer2D::shutdown();
    }

    void Application::run()
    {
        while (!m_Window->shouldClose())
        {
            Time::update();

            RenderCommand::setClearColor(0.05f, 0.05f, 0.08f, 1.0f);
            RenderCommand::clear();

            m_Scene->update(Time::getDeltaTime());
            m_Scene->render(*m_Camera);

            m_Window->swapBuffers();
            m_Window->pollEvents();
        }
    }

}
