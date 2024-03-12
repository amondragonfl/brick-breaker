#include <iostream>
#include "GameEngine.hpp"

int main(int argc, char* argv[])
{
    GameEngine game;
    try {
        game.init();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error initializing game: " << e.what() << std::endl;
        return 1;
    }
    while (game.running())
    {
        game.handleEvents();
        game.update();
        game.render();
    }
    game.clean();
    return 0;
}