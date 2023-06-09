#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <chrono>

#include "../include/Game.h"
#include "../entt/entt.hpp"
#include "../include/components/Transform.h"
#include "../include/components/Sprite.h"
#include "../include/components/Collider.h"
#include "../include/components/AI.h"
#include "../include/components/Ball.h"
#include "../include/components/Score.h"

Game::Game(const char* title, int xPos, int yPos, int width, int height, bool fullScreen) :
            running{}, window{}, backgroundRect{} {
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

    backgroundTexture = TextureManager::LoadTexture(window.getRenderer(), "../assets/background.png");
    backgroundRect = {window.width / 2 - 8, 0, 16, 768};

    fontManager.renderer = window.getRenderer();
    fontManager.loadFont("arial128", "../assets/arial.ttf" ,128);
    fontManager.loadFont("arial32", "../assets/arial.ttf" ,32);

    soundManager.loadSound("../assets/paddleCollision.wav", "paddleCollision");
    soundManager.loadSound("../assets/wallCollision.wav", "wallCollision");
    soundManager.loadSound("../assets/score.wav", "score");

    running = true;
}

Game::~Game() {
    SDL_DestroyTexture(backgroundTexture);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

void Game::init() {
    auto playerPaddle = registry.create();
    auto aiPaddle = registry.create();
    auto ball = registry.create();

    registry.emplace<Transform>(playerPaddle, window.width - 50 - 16, window.height / 2 - 50, 5.0);
    registry.emplace<Sprite>(playerPaddle, window.getRenderer(), "../assets/paddle.png");
    registry.emplace<Player>(playerPaddle);
    registry.emplace<Collider>(playerPaddle, "playerPaddle");
    registry.emplace<Score>(playerPaddle, &fontManager, "arial128", 600, 50, 255, 255, 255, 0);

    registry.emplace<Transform>(aiPaddle, 50, window.height / 2 - 50, 5.0);
    registry.emplace<Sprite>(aiPaddle, window.getRenderer(), "../assets/paddle.png");
    registry.emplace<AI>(aiPaddle);
    registry.emplace<Collider>(aiPaddle, "aiPaddle");
    registry.emplace<Score>(aiPaddle, &fontManager, "arial128", 350, 50, 255, 255, 255, 0);

    registry.emplace<Transform>(ball, window.width / 2 - 8, window.height / 2 - 8, -1.0, 0.0, 5.0);
    registry.emplace<Sprite>(ball, window.getRenderer(), "../assets/ball.png");
    registry.emplace<Ball>(ball, 6.0, 1.0, 4.0, 8.0);
    registry.emplace<Collider>(ball, "ball");

    dispatcher.sink<KeyDown>().connect<&MovementSystem::onKeyDown>(movementSystem);
    dispatcher.sink<KeyUp>().connect<&MovementSystem::onKeyUp>(movementSystem);

    collisionHolder.player = playerPaddle;
    collisionHolder.ai = aiPaddle;
    collisionHolder.ball = ball;
    collisionHolder.registry = &registry;

    gameLoop();
}

using namespace std::literals;
auto constexpr dt = std::chrono::duration<long long, std::ratio<1, 60>>{1};
using Clock = std::chrono::steady_clock;
using duration = decltype(Clock::duration{} + dt);
using time_point = std::chrono::time_point<Clock, duration>;

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
            dispatcher.trigger(KeyDown{window.event.key.keysym.sym});
            break;

        case SDL_KEYUP:
            dispatcher.trigger(KeyUp{window.event.key.keysym.sym});
            break;

        default:
            break;
    }
}

void Game::update() {
    movementSystem.update(&soundManager, &fontManager, window, registry);
    collisionSystem.update(&soundManager, collisionHolder);
    aiSystem.update(window, registry);
}

void Game::render() {
    SDL_RenderClear(window.getRenderer());

    SDL_RenderCopy(window.getRenderer(), backgroundTexture, {}, &backgroundRect);
    renderSystem.render(window.getRenderer(), registry);

    SDL_RenderPresent(window.getRenderer());
}