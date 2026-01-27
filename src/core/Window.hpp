#pragma once

#include <string>

struct GLFWwindow;

namespace SolarSystem2D 
{

    class Window 
    {
    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        void pollEvents();
        bool shouldClose() const;
        void swapBuffers();

    private:
        void init();

    private:
        int m_width;
        int m_height;
        std::string m_title;
        GLFWwindow* m_window;
    };

} 
