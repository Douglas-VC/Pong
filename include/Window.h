#ifndef PONG_WINDOW_H
#define PONG_WINDOW_H
#include <SDL2/SDL.h>

class Window {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    SDL_Event event;

    Window();
    ~Window();

    void create(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
    [[nodiscard]] SDL_Renderer* getRenderer() const noexcept;
};

#endif //PONG_WINDOW_H
