#include "Application.hpp"

#include <iostream>

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
    while (m_running) {
        update();
        m_running = false; // временно, один кадр
    }
}

void Application::update()
{
    std::cout << "Application update\n";
}

void Application::shutdown()
{
    std::cout << "Application shutdown\n";
}
