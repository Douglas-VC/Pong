#include "../include/Game.h"

int main() {
    Game pong;
    pong.init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);

    return 0;
}