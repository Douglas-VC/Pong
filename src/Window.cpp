#include <iostream>
#include "../include/Window.h"

Window::Window() : window{nullptr}, renderer{nullptr} {};

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void Window::create(const char* title, int xPos, int yPos, int width, int height, bool fullScreen) {
    int windowFlag {0};
    if (fullScreen)
        windowFlag = SDL_WINDOW_FULLSCREEN;

    window = SDL_CreateWindow(title, xPos, yPos, width, height, windowFlag);
    if (!window) {
        std::cerr << "ERROR: Unable to create window: " << SDL_GetError() << std::endl;
        return;
    }
    std::cout << "Window created!" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "ERROR: Unable to create renderer: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    std::cout << "Renderer created!" << std::endl;
}

SDL_Renderer* Window::getRenderer() const noexcept {
    return renderer;
}
