#ifndef PONG_SPRITECOMPONENT_H
#define PONG_SPRITECOMPONENT_H

#include <SDL2/SDL.h>

#include "../ECS.h"
#include "TransformComponent.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect;
    SDL_Rect targetRect;

public:
    explicit SpriteComponent(const char *path) : transform{}, texture{}, srcRect{}, targetRect{} {
        setTex(path);
        SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h);
    };

    ~SpriteComponent() override {
        SDL_DestroyTexture(texture);
    }

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        targetRect.h = srcRect.h * transform->scale;
        targetRect.w = srcRect.w * transform->scale;
        transform->height = srcRect.h * transform->scale;
        transform->width = srcRect.w * transform->scale;
    }

    void setTex(const char *path) {
        texture = TextureManager::LoadTexture(path);
    }

    void update(float deltaTime) override {
        targetRect.x = static_cast<int>(transform->position.x);
        targetRect.y = static_cast<int>(transform->position.y);
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, targetRect);
    }
};

#endif //PONG_SPRITECOMPONENT_H
