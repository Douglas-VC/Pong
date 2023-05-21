#ifndef PONG_GAME_H
#define PONG_GAME_H
#include <SDL2/SDL.h>

class Game {
private:
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

    void handleEvents();
    void update();
    void render();

    [[nodiscard]] bool isRunning() const;
};


#endif //PONG_GAME_H
