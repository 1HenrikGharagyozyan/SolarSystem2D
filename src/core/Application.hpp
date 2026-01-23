#pragma once

class Application 
{
public:
    Application();
    ~Application();

    void run();

private:
    void init();
    void update();
    void shutdown();

private:
    bool m_running;
};
