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

        void PoolEvents();
        bool ShouldClose() const;
        void SwapBuffers();

    private:
        void Init();

    private:
        int m_Width;
        int m_Height;
        std::string m_Title;

        GLFWwindow* m_Window;
    };

}