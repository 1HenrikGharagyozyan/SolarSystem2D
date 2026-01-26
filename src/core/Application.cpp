#include "Application.hpp"

#include "Window.hpp"
#include "Time.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <chrono>
#include <stdexcept>

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
        m_window = std::make_unique<Window>(1280, 720, "SolarSystem2D");
        std::cout << "Application initialized\n";
    }

    void Application::run()
    {
        while (m_running)
        {
            update(0.0f);
            render();
            m_window->PoolEvents();
        }
    }

    void Application::update(float deltaTime)
    {
        (void)deltaTime;
    }

    void Application::render()
    {
        glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_window->SwapBuffers();
    }

    void Application::shutdown()
    {
        std::cout << "Application shutdown\n";
    }

}