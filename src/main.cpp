#include "../include/Game.h"

int main() {
    Game game;
    game.init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);

    while(game.isRunning()) {
        game.handleEvents();
        game.update();
        game.render();
    }

    return 0;
}
