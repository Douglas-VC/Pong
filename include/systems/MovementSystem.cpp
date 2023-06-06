#include <SDL2/SDL.h>
#include "MovementSystem.h"
#include "../Random.h"
#include "../components/Transform.h"
#include "../components/Sprite.h"
#include "../components/Ball.h"
#include "../components/AI.h"
#include "../components/Score.h"

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

float randDir(const float vel) {
    switch (randomInt(0, 1)) {
        case 0:
            return vel;

        case 1:
            return -vel;
    }
}

void MovementSystem::update(SoundManager *soundManager, FontManager *fontManager, Window &window, entt::registry& registry) {
    auto playerView = registry.view<Player, Transform, Sprite>();
    for(auto entity: playerView) {
        auto &player = playerView.get<Player>(entity);
        auto &transform = playerView.get<Transform>(entity);
        auto &sprite = playerView.get<Sprite>(entity);

        player.moveDirection = playerMovement;

        if (player.moveDirection == Player::MoveDirection::UP) {
            transform.position.y -= 8.0;
        } else if (player.moveDirection == Player::MoveDirection::DOWN) {
            transform.position.y += 8.0;
        }

        if (transform.position.y < 0.0) {
            transform.position.y = 0.0;
        } else if (transform.position.y > static_cast<float>(window.height - sprite.height)) {
            transform.position.y = static_cast<float>(window.height - sprite.height);
        }
    }

    auto ballView = registry.view<Ball, Transform, Sprite>();
    auto playerScoreView = registry.view<Player, Score>();
    auto aiScoreView = registry.view<AI, Score>();
    for(auto entity: ballView) {
        auto &ball = ballView.get<Ball>(entity);
        auto &transform = playerView.get<Transform>(entity);
        auto &sprite = playerView.get<Sprite>(entity);

        transform.position.x += ball.velX;
        transform.position.y += ball.velY;

        if (transform.position.x < 0.0) {
            transform.position.x  = window.width / 2.0 - sprite.width / 2.0;
            transform.position.y = window.height / 2.0 - sprite.height / 2.0;
            ball.velX = 6.0f;
            ball.velY = randDir(randomFloat(ball.minVel, ball.maxVel));
            for(auto scoreEntity: aiScoreView) {
                auto &aiScore = aiScoreView.get<Score>(scoreEntity);
                aiScore.score++;
                SDL_DestroyTexture(aiScore.textTexture);
                aiScore.textTexture = fontManager->getTextTexture("arial128", std::to_string(aiScore.score), aiScore.textColor);
            }
            soundManager->playSound("score");
        } else if (transform.position.x > static_cast<float>(window.width - sprite.width)) {
            transform.position.x  = window.width / 2.0 - sprite.width / 2.0;
            transform.position.y = window.height / 2.0 - sprite.height / 2.0;
            ball.velX = 6.0f;
            ball.velY = randDir(randomFloat(ball.minVel, ball.maxVel));
            for(auto scoreEntity: playerScoreView) {
                auto &playerScore = playerScoreView.get<Score>(scoreEntity);
                playerScore.score++;
                SDL_DestroyTexture(playerScore.textTexture);
                playerScore.textTexture = fontManager->getTextTexture("arial128", std::to_string(playerScore.score), playerScore.textColor);
            }
            soundManager->playSound("score");
        }

        if (transform.position.y < 0.0) {
            transform.position.y = 0.0;
            ball.velY *= -1;
            soundManager->playSound("wallCollision");
        } else if (transform.position.y > static_cast<float>(window.height - sprite.height)) {
            transform.position.y = static_cast<float>(window.height - sprite.height);
            ball.velY *= -1;
            soundManager->playSound("wallCollision");
        }
    }
}
