#include "Window.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

namespace SolarSystem2D
{

    Window::Window(int width, int height, const std::string& title)
        : m_Width(width)
        , m_Height(height)
        , m_Title(title)
        , m_Window(nullptr)
    {
        Init();   
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::Init()
    {
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW\n";
            return;
        }
        
        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
        if (!m_Window)
        {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            return;
        }
    }

    void Window::PoolEvents()
    {
        glfwPollEvents();
    }

    bool Window::ShouldClose() const
    {
        return glfwWindowShouldClose(m_Window);
    }

}