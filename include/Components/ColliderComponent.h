#ifndef PONG_COLLIDERCOMPONENT_H
#define PONG_COLLIDERCOMPONENT_H

#include <SDL2/SDL.h>

#include <utility>

#include "../ECS.h"
#include "TransformComponent.h"
#include "../TextureManager.h"

class ColliderComponent : public Component {
public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent *transform;

    explicit ColliderComponent(std::string t) : tag{std::move(t)}, collider{}, transform{} {};

    void init() override {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }

    void update(float deltaTime) override {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.h = transform->height * transform->scale;
        collider.w = transform->width * transform->scale;
    }
};

#endif //PONG_COLLIDERCOMPONENT_H
