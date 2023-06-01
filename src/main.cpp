#include "../include/Game.h"

int main() {
    Game pong("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);
    pong.init();

    return 0;
}