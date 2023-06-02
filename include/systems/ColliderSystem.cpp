#include <iostream>
#include "ColliderSystem.h"
#include "../components/Transform.h"
#include "../components/Sprite.h"
#include "../components/Collider.h"
#include "../components/Player.h"
#include "../components/Ball.h"

void ColliderSystem::update(CollisionHolder &collisionHolder) {
    auto &ballVel = collisionHolder.registry->get<Ball>(collisionHolder.ball);

    if (ballVel.immunityTicks > 0) {
        ballVel.immunityTicks--;
        return;
    }

    auto view = collisionHolder.registry->view<Transform, Sprite, Collider>();
    for(auto entity: view) {
        auto &transform = view.get<Transform>(entity);
        auto &sprite = view.get<Sprite>(entity);
        auto &collider = view.get<Collider>(entity);

        collider.collider = {static_cast<int>(transform.position.x), static_cast<int>(transform.position.y), sprite.width, sprite.height};
    }

    auto &player = collisionHolder.registry->get<Collider>(collisionHolder.player);
    auto &ai = collisionHolder.registry->get<Collider>(collisionHolder.ai);
    auto &ball = collisionHolder.registry->get<Collider>(collisionHolder.ball);

    if (SDL_HasIntersection(&player.collider, &ball.collider) == SDL_TRUE ||
        SDL_HasIntersection(&ai.collider, &ball.collider) == SDL_TRUE) {
        ballVel.velX *= -1;
        ballVel.immunityTicks = 5;
    }
}
