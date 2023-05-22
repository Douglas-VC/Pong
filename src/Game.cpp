#include "../include/Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Game::Game() : running{false}, window{nullptr}, renderer{nullptr} {};

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }
    std::cout << "SDL Subsystems Initialized..." << std::endl;

    int windowFlag {0};
    if (fullScreen)
        windowFlag = SDL_WINDOW_FULLSCREEN;

    window = SDL_CreateWindow(title, xPos, yPos, width, height, windowFlag);
    if (!window) {
        std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
        return;
    }
    std::cout << "Window created!" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    std::cout << "Renderer created!" << std::endl;

    running = true;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;

        default:
            break;
    }
}

void Game::update() {
}

void Game::render() {
    SDL_RenderClear(renderer);


    SDL_RenderPresent(renderer);
}

bool Game::isRunning() const {
    return running;
}
