#include "Application.hpp"

#include "Window.hpp"
#include "Time.hpp"

#include "renderer/Renderer.hpp"
#include "renderer/Renderer2D.hpp"

namespace SolarSystem2D
{

    Application::Application()
        : m_running(true)
    {
        init();
    }

    Application::~Application()
    {
        shutdown();
    }

    void Application::init()
    {
        m_window = std::make_unique<Window>(1280, 720, "Solar System 2D");
        Renderer::init();
        Renderer2D::init();
    }

    void Application::run()
    {
        while (m_running && !m_window->shouldClose())
        {
            Time::update();
            update(Time::deltaTime());
            render();
            m_window->pollEvents();
        }
    }

    void Application::update(float)
    {
    }

    void Application::render()
    {
        Renderer::beginFrame();
        Renderer2D::drawTriangle();
        m_window->swapBuffers();
    }

    void Application::shutdown()
    {
    }

}
