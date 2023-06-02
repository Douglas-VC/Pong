#include <SDL2/SDL.h>
#include <iostream>
#include "MovementSystem.h"
#include "../components/Transform.h"
#include "../components/Sprite.h"

void MovementSystem::onKeyDown(const KeyDown& key_down) noexcept {
    switch (key_down.keyCode) {
        case SDLK_s:
        case SDLK_DOWN:
            playerMovement = Player::MoveDirection::DOWN;
            break;
        case SDLK_w:
        case SDLK_UP:
            playerMovement = Player::MoveDirection::UP;
            break;
    }
}

void MovementSystem::onKeyUp(const KeyUp& key_up) noexcept {
    switch (key_up.keyCode) {
        case SDLK_s:
        case SDLK_DOWN:
        case SDLK_w:
        case SDLK_UP:
            playerMovement = Player::MoveDirection::STOPPED;
            break;
    }
}

void MovementSystem::update(Window &window, entt::registry& registry) {
    auto playerView = registry.view<Player, Transform, Sprite>();
    for(auto entity: playerView) {
        auto &player = playerView.get<Player>(entity);
        auto &transform = playerView.get<Transform>(entity);
        auto &sprite = playerView.get<Sprite>(entity);
        player.moveDirection = playerMovement;

        if (player.moveDirection == Player::MoveDirection::UP) {
            transform.position.y -= 5.0;
        } else if (player.moveDirection == Player::MoveDirection::DOWN) {
            transform.position.y += 5.0;
        }

        if (transform.position.y < 0.0) {
            transform.position.y = 0.0;
        } else if (transform.position.y > static_cast<float>(window.height - sprite.height)) {
            transform.position.y = static_cast<float>(window.height - sprite.height);
        }
    }


}
