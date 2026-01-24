#include "Application.hpp"

#include "Window.hpp"   
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
        m_window = std::make_shared<Window>(1280, 720, "SolarSystem2D");
        std::cout << "Application initialized\n";
    }

    void Application::run()
    {
        while (m_running) 
        {
            Time::Update();
            update(Time::GetDeltaTime());
            m_window->PoolEvents();
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