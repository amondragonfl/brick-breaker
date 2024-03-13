#include <iostream>
#include "GameEngine.hpp"
#include "TimeManager.hpp"

int main(int argc, char* argv[])
{
    GameEngine game;
    TimeManager time;

    try {
        game.init();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error initializing game: " << e.what() << std::endl;
        return 1;
    }
    while (game.running())
    {
        time.recordFrameStart();
        game.handleEvents();
        game.update();
        game.render();
        time.recordFrameEnd(); // Limits FPS
    }
    game.clean();
    return 0;
}