#include "core/Application.hpp"

#include "core/Window.hpp"
#include "core/Time.hpp"

#include "renderer/Renderer2D.hpp"
#include "renderer/OrthographicCamera.hpp"

#include "scene/Planet.hpp"

#include <glad/glad.h>

namespace SolarSystem2D 
{

    Application::Application()
    {
        m_Window = std::make_unique<Window>(1280, 720, "SolarSystem2D");

        Renderer2D::init();

        // Камера под 16:9
        m_Camera = std::make_unique<OrthographicCamera>(
            -1.6f, 1.6f,
            -0.9f, 0.9f
        );

        // Планеты
        m_Sun   = std::make_unique<Planet>(0.0f, 0.0f, 0.4f);
        m_Earth = std::make_unique<Planet>(0.8f, 1.0f, 0.15f);
        m_Moon  = std::make_unique<Planet>(0.25f, 3.0f, 0.07f);
    }

    Application::~Application() = default;

    void Application::run()
    {
        while (!m_Window->shouldClose())
        {
            Time::update();

            update(Time::getDeltaTime());
            render();

            m_Window->swapBuffers();
            m_Window->pollEvents();
        }
    }

    void Application::update(float deltaTime)
    {
        // Update planets
        m_Earth->update(deltaTime);
        m_Moon->update(deltaTime);
    }

    void Application::render()
    {
        glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Renderer2D::beginScene(*m_Camera);

        // Sun
        Renderer2D::drawQuad(m_Sun->getTransform());

        // Earth
        Renderer2D::drawQuad(m_Earth->getTransform());

        // Moon (around Earth — manually for now)
        Transform moonWorld = m_Moon->getTransform();
        moonWorld.position += m_Earth->getTransform().position;
        Renderer2D::drawQuad(moonWorld);

    }

} 
