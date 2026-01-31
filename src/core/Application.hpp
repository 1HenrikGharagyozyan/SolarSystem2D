#pragma once

#include <memory>

namespace SolarSystem2D
{

    class Window;
    class OrthographicCamera;

    class Entity;
    class Planet;
    class Orbit;

    class Application
    {
    public:
        Application();
        ~Application();

        void run();

    private:
        void update(float dt);
        void render();

    private:
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<OrthographicCamera> m_Camera;

        // Entities
        std::unique_ptr<Entity> m_SunEntity;

        std::unique_ptr<Entity> m_EarthOrbitEntity;
        std::unique_ptr<Entity> m_EarthVisualEntity;

        std::unique_ptr<Entity> m_MoonOrbitEntity;
        std::unique_ptr<Entity> m_MoonVisualEntity;

        // Components
        std::unique_ptr<Planet> m_Sun;
        std::unique_ptr<Planet> m_Earth;
        std::unique_ptr<Planet> m_Moon;

        std::unique_ptr<Orbit> m_EarthOrbit;
        std::unique_ptr<Orbit> m_MoonOrbit;
    };
    
}
