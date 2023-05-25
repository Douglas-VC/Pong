#ifndef PONG_SPRITECOMPONENT_H
#define PONG_SPRITECOMPONENT_H

#include <SDL2/SDL.h>

#include "../ECS.h"
#include "PositionComponent.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect;
    SDL_Rect targetRect;

public:
    explicit SpriteComponent(const char *path) : position{}, texture{}, srcRect{}, targetRect{} {
        setTex(path);
        SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h);
        targetRect = srcRect;
    };

    void init() override {
        position = &entity->getComponent<PositionComponent>();
    }

    void setTex(const char *path) {
        texture = TextureManager::LoadTexture(path);
    }

    void update(float deltaTime) override {
        targetRect.x = position->x();
        targetRect.y = position->y();
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, targetRect);
    }
};

#endif //PONG_SPRITECOMPONENT_H
