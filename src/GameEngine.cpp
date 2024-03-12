#include "GameEngine.hpp" 

GameEngine::GameEngine() : isRunning(false), window(nullptr), renderer(nullptr) {
}

GameEngine::~GameEngine() {
    if (isRunning) {
        clean();
    }
}

bool GameEngine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
    }
    window = SDL_CreateWindow(
        "Brick Breaker",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        300,
        500,
        0
    );
    if (!window) {
        clean();
        throw std::runtime_error("Window initialization failed: " + std::string(SDL_GetError()));
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        clean();
        throw std::runtime_error("Renderer initialization failed: " + std::string(SDL_GetError()));
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    isRunning = true;
    return true;
}

void GameEngine::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
    default:
        break;
    }
}

void GameEngine::update() {
}

void GameEngine::render() {
    SDL_RenderClear(renderer); 
    SDL_RenderPresent(renderer);
}

void GameEngine::clean() {
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    SDL_Quit();
}
