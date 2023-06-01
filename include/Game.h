#ifndef PONG_GAME_H
#define PONG_GAME_H
#include <SDL2/SDL.h>
#include "../entt/entt.hpp"
#include "Window.h"

class Game {
private:
    bool running;
    Window window;
    entt::registry m_registry;

public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

private:
    void gameLoop();
    void handleEvents();
    void update();
    void render();
};

#endif //PONG_GAME_H