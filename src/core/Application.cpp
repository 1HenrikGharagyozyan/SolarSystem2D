#include "Application.hpp"

#include "Time.hpp"

#include <iostream>
#include <chrono>

float SolarSystem2D::Time::s_DeltaTime = 0.0f;

namespace SolarSystem2D
{

    static auto s_LastTime = std::chrono::high_resolution_clock::now();

    void Time::Update()
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> delta = currentTime - s_LastTime;
        s_DeltaTime = delta.count();
        s_LastTime = currentTime;
    }

    float Time::GetDeltaTime()
    {
        return s_DeltaTime;
    }   

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
        std::cout << "Application initialized\n";
    }

    void Application::run()
    {
        while (m_running) 
        {
            Time::Update();
            update(Time::GetDeltaTime());

            if (Time::GetDeltaTime() > 1.0f) // Example condition to stop the loop
                m_running = false;
        }
    }

    void Application::update(float deltaTime)
    {
        std::cout << "Update deltaTime: " << deltaTime << " seconds\n";
    }

    void Application::shutdown()
    {
        std::cout << "Application shutdown\n";
    }

}