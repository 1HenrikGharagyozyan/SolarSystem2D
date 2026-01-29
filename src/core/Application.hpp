#pragma once

#include <memory>

namespace SolarSystem2D 
{

    class Window;
    class OrthographicCamera;
    class Planet;

    class Application 
    {
    public:
        Application();
        ~Application();

        void run();

    private:
        void update(float deltaTime);
        void render();

    private:
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<OrthographicCamera> m_Camera;

        std::unique_ptr<Planet> m_Sun;
        std::unique_ptr<Planet> m_Earth;
        std::unique_ptr<Planet> m_Moon;
    };

}
