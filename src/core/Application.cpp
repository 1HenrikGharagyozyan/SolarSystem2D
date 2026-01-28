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
        OrthographicCamera camera(-1.6f, 1.6f, -0.9f, 0.9f);
        Renderer2D::beginScene(camera);
        Renderer2D::drawQuad();
        m_window->swapBuffers();
    }

    void Application::shutdown()
    {
    }

}
