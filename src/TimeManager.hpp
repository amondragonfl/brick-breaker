#pragma once 
#include <chrono>
#include <thread>

class TimeManager
{
private:
    int targetFps = 60;
    int targetFrameTime = 1000 / targetFps;
    std::chrono::steady_clock::time_point frameStart;
    static int deltaTime;
public:
    void recordFrameStart();
    void recordFrameEnd();
    static int getDeltaTime();

};