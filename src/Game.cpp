#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <chrono>

#include "../include/Game.h"
#include "../entt/entt.hpp"
#include "../include/Components/TransformComponent.h"
#include "../include/Components/SpriteComponent.h"
#include "../include/Components/ColliderComponent.h"
#include "../include/Components/WindowBoundComponent.h"

using namespace std::literals;
auto constexpr dt = std::chrono::duration<long long, std::ratio<1, 60>>{1};
using Clock = std::chrono::steady_clock;
using duration = decltype(Clock::duration{} + dt);
using time_point = std::chrono::time_point<Clock, duration>;

Manager manager;
auto &paddle1(manager.addEntity());
auto &paddle2(manager.addEntity());
auto &ball(manager.addEntity());

enum groupLabels : std::size_t {
};

Game::Game() : running{false}, window{} {};

Game::~Game() {
    IMG_Quit();
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cerr << "ERROR: Unable to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }
    std::cout << "SDL Subsystems Initialized..." << std::endl;

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        std::cerr << "ERROR: Unable to initialize Image library: " << SDL_GetError() << std::endl;
        return;
    }
    std::cout << "SDL Image library loaded!" << std::endl;

    window.create(title, xPos, yPos, width, height, fullScreen);

    running = true;

    paddle1.addComponent<TransformComponent>(50, height / 2 - 50);
    paddle1.addComponent<SpriteComponent>("../assets/paddle.png");
    paddle1.addComponent<ColliderComponent>("paddle1");
    paddle1.addComponent<WindowBoundComponent>(height, width);
    paddle1.getComponent<TransformComponent>().speed = 5;

    paddle2.addComponent<TransformComponent>(width - 50 - 16, height / 2 - 50);
    paddle2.addComponent<SpriteComponent>("../assets/paddle.png");
    paddle2.addComponent<ColliderComponent>("paddle2");
    paddle2.addComponent<WindowBoundComponent>(height, width);
    paddle2.getComponent<TransformComponent>().speed = 5;

    ball.addComponent<TransformComponent>(width / 2 - 8, height / 2 - 8);
    ball.addComponent<SpriteComponent>("../assets/ball.png");
    ball.addComponent<ColliderComponent>("ball");
    ball.addComponent<WindowBoundComponent>(height, width);
    ball.getComponent<TransformComponent>().velocity = {-1.0, 0.0};
    ball.getComponent<TransformComponent>().speed = 3;

    gameLoop();
}

void Game::gameLoop() {
    time_point t {};
    time_point currentTime = Clock::now();
    duration accumulator = 0s;

    while(running) {
        handleEvents();

        time_point newTime = Clock::now();
        auto frameTime = newTime - currentTime;
        if (frameTime > 250ms)
            frameTime = 250ms;
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt) {
            update();
            t += dt;
            accumulator -= dt;
        }
        render();
    }
}

void Game::handleEvents() {
    SDL_PollEvent(&window.event);
    switch (window.event.type) {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_KEYDOWN:
            switch (window.event.key.keysym.sym) {
                case SDLK_w:
                    paddle1.getComponent<TransformComponent>().velocity = {0.0, -1.0};
                    break;
                case SDLK_s:
                    paddle1.getComponent<TransformComponent>().velocity = {0.0, 1.0};
                    break;
                case SDLK_UP:
                    paddle2.getComponent<TransformComponent>().velocity = {0.0, -1.0};
                    break;
                case SDLK_DOWN:
                    paddle2.getComponent<TransformComponent>().velocity = {0.0, 1.0};
                    break;
            }
            break;

        case SDL_KEYUP:
            switch (window.event.key.keysym.sym) {
                case SDLK_w:
                case SDLK_s:
                    paddle1.getComponent<TransformComponent>().velocity = {0.0, 0.0};
                    break;
                case SDLK_UP:
                case SDLK_DOWN:
                    paddle2.getComponent<TransformComponent>().velocity = {0.0, 0.0};
                    break;
            }
            break;

        default:
            break;
    }
}

void Game::update() {
    manager.refresh();
    manager.update(1.0f);

    if (SDL_HasIntersection(&paddle1.getComponent<ColliderComponent>().collider,
                            &ball.getComponent<ColliderComponent>().collider) == SDL_TRUE ||
        SDL_HasIntersection(&paddle2.getComponent<ColliderComponent>().collider,
                            &ball.getComponent<ColliderComponent>().collider) == SDL_TRUE) {
        
        ball.getComponent<TransformComponent>().velocity *= -1.0;
    }
}

void Game::render() {
    SDL_RenderClear(window.getRenderer());

    manager.draw();

    SDL_RenderPresent(window.getRenderer());
}