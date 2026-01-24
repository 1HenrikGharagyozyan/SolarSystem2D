#pragma once

namespace SolarSystem2D
{

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
    };
    
}