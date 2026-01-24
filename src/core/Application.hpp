#pragma once

#include <memory>

namespace SolarSystem2D
{
    class Window;

    class Application 
    {
    public:
        Application();
        ~Application();

        void run();

    private:
        void init();
        void update(float deltaTime);
        void shutdown();

    private:
        bool m_running;
        std::shared_ptr<Window> m_window;
    };
    
}