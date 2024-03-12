#pragma once
#include "SDL.h"
#include <iostream>

class GameEngine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

public:
    GameEngine();
    ~GameEngine();

    bool init();
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }
};