#include "core/Application.hpp"

#include "core/Window.hpp"
#include "core/Time.hpp"

#include "renderer/Renderer2D.hpp"
#include "renderer/DebugRenderer2D.hpp"
#include "renderer/OrthographicCamera.hpp"

#include "scene/Entity.hpp"
#include "scene/Planet.hpp"
#include "scene/Orbit.hpp"

#include <glad/glad.h>

namespace SolarSystem2D
{

    Application::Application()
    {
        m_Window = std::make_unique<Window>(1280, 720, "SolarSystem2D");

        Renderer2D::init();
        DebugRenderer2D::init();

        m_Camera = std::make_unique<OrthographicCamera>(
            -1.6f, 1.6f,
            -0.9f, 0.9f
        );

    
        // Создаём Entity
        m_SunEntity = std::make_unique<Entity>("Sun");
        m_EarthOrbitEntity = std::make_unique<Entity>("EarthOrbit");
        m_EarthVisualEntity = std::make_unique<Entity>("EarthVisual");
        m_MoonOrbitEntity = std::make_unique<Entity>("MoonOrbit");
        m_MoonVisualEntity = std::make_unique<Entity>("MoonVisual");

        // Иерархия
        m_EarthOrbitEntity->getTransform().setParent(&m_SunEntity->getTransform());
        m_EarthVisualEntity->getTransform().setParent(&m_EarthOrbitEntity->getTransform());

        m_MoonOrbitEntity->getTransform().setParent(&m_EarthOrbitEntity->getTransform());
        m_MoonVisualEntity->getTransform().setParent(&m_MoonOrbitEntity->getTransform());

        // Планеты
        m_Sun = std::make_unique<Planet>(*m_SunEntity, 0.4f);
        m_Earth = std::make_unique<Planet>(*m_EarthOrbitEntity, 0.15f);
        m_Moon = std::make_unique<Planet>(*m_MoonOrbitEntity, 0.07f);


        m_EarthOrbit = std::make_unique<Orbit>(
            *m_EarthOrbitEntity, 1.0f, 1.0f);

        m_MoonOrbit = std::make_unique<Orbit>(
            *m_MoonOrbitEntity, 0.25f, 3.0f);
    }

    Application::~Application()
    {
        Renderer2D::shutdown();
        DebugRenderer2D::shutdown();
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
        m_EarthOrbit->update(dt);
        m_MoonOrbit->update(dt);
    }

    void Application::render()
    {
        glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Renderer2D::beginScene(*m_Camera);

        Renderer2D::drawQuad(m_SunEntity->getTransform().getWorldMatrix(), glm::vec4(1.0f,0.9f,0.0f,1.0f));
        Renderer2D::drawQuad(m_EarthVisualEntity->getTransform().getWorldMatrix(), glm::vec4(0.2f,0.5f,1.0f,1.0f));
        Renderer2D::drawQuad(m_MoonVisualEntity->getTransform().getWorldMatrix(), glm::vec4(0.8f,0.8f,0.8f,1.0f));


        DebugRenderer2D::beginScene(*m_Camera);

        // Earth Orbit
        DebugRenderer2D::drawCircle(
            glm::vec2(0.0f),
            1.0f, 
            {0.4f, 0.4f, 0.4f, 1.0f}
        );

        // Moon orbit (relative to Earth orbit center)
        glm::vec3 earthPos =
            glm::vec3(m_EarthOrbitEntity->getTransform().getWorldMatrix()[3]);

        DebugRenderer2D::drawCircle(
            {earthPos.x, earthPos.y},
            0.25f,
            {0.6f, 0.6f, 0.6f, 1.0f}
        );
    }

}
