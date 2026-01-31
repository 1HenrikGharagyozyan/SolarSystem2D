#include "core/Application.hpp"

#include "core/Window.hpp"
#include "core/Time.hpp"

#include "renderer/Renderer2D.hpp"
#include "renderer/OrthographicCamera.hpp"

#include "scene/Entity.hpp"
#include "scene/Planet.hpp"

#include <glad/glad.h>
#include <iostream>

namespace SolarSystem2D
{

    Application::~Application()
    {
        // Ensure renderer releases GL resources while the Window (GL context) is still alive
        Renderer2D::shutdown();
    }

    Application::Application()
    {
        m_Window = std::make_unique<Window>(1280, 720, "SolarSystem2D");

        Renderer2D::init();

        m_Camera = std::make_unique<OrthographicCamera>(
            -1.6f, 1.6f,
            -0.9f, 0.9f);

        // Entities
        m_SunEntity = std::make_unique<Entity>("Sun");
        m_EarthEntity = std::make_unique<Entity>("Earth");
        m_MoonEntity = std::make_unique<Entity>("Moon");

        // Hierarchy
        m_EarthEntity->getTransform().setParent(&m_SunEntity->getTransform());
        m_MoonEntity->getTransform().setParent(&m_EarthEntity->getTransform());

        // Planets
        m_Sun = std::make_unique<Planet>(*m_SunEntity, 0.0f, 0.0f, 0.4f);
        m_Earth = std::make_unique<Planet>(*m_EarthEntity, 1.0f, 1.0f, 0.15f);
        m_Moon = std::make_unique<Planet>(*m_MoonEntity, 0.25f, 3.0f, 0.07f);
    }

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

    void Application::update(float dt)
    {
        m_Earth->update(dt);
        m_Moon->update(dt);
    }

    void Application::render()
    {
        glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Renderer2D::beginScene(*m_Camera);

        Renderer2D::drawQuad(m_SunEntity->getTransform().getWorldMatrix(), glm::vec4(1.0f, 0.9f, 0.0f, 1.0f));   // Sun (yellow)
        Renderer2D::drawQuad(m_EarthEntity->getTransform().getWorldMatrix(), glm::vec4(0.2f, 0.5f, 1.0f, 1.0f)); // Earth (blue)
        Renderer2D::drawQuad(m_MoonEntity->getTransform().getWorldMatrix(), glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));  // Moon (grey)

        // Debug: print world positions
        {
            const glm::mat4 &sunWorld = m_SunEntity->getTransform().getWorldMatrix();
            const glm::mat4 &earthWorld = m_EarthEntity->getTransform().getWorldMatrix();
            const glm::mat4 &moonWorld = m_MoonEntity->getTransform().getWorldMatrix();

            glm::vec3 sunPos = glm::vec3(sunWorld[3]);
            glm::vec3 earthPos = glm::vec3(earthWorld[3]);
            glm::vec3 moonPos = glm::vec3(moonWorld[3]);

            std::cout << "Positions -> Sun(" << sunPos.x << "," << sunPos.y << ") "
                      << "Earth(" << earthPos.x << "," << earthPos.y << ") "
                      << "Moon(" << moonPos.x << "," << moonPos.y << ")\n";
        }
    }

}
