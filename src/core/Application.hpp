#pragma once
#include <memory>

namespace SolarSystem2D
{

    class Window;
    class OrthographicCamera;
    class Scene;

    class Application
    {
    public:
        Application();
        ~Application();

        void run();

    private:
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<OrthographicCamera> m_Camera;
        std::unique_ptr<Scene> m_Scene;
    };
    
}
