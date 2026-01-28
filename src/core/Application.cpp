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
        Transform t1;
        t1.position = { 0.0f, 0.0f, 0.0f };
        t1.scale = { 0.5f, 0.5f, 1.0f };

        Renderer2D::drawQuad(t1);

        Transform t2;
        t2.position = { 0.8f, 0.0f, 0.0f };
        t2.scale = { 0.2f, 0.2f, 1.0f };

        Renderer2D::drawQuad(t2);

        m_window->swapBuffers();
    }

    void Application::shutdown()
    {
    }

}
