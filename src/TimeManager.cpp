#include "TimeManager.hpp"

int TimeManager::deltaTime = 0; 

void TimeManager::recordFrameStart() {
    frameStart = std::chrono::steady_clock::now();
}

void TimeManager::recordFrameEnd() {
    auto frameEnd = std::chrono::steady_clock::now();
    auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
    deltaTime = frameDuration.count();
    if (targetFrameTime > deltaTime) {
        std::chrono::milliseconds sleepTime(targetFrameTime - deltaTime);
        std::this_thread::sleep_for(sleepTime);
    }
}

int TimeManager::getDeltaTime() {
    return deltaTime;
}