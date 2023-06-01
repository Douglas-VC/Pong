#ifndef PONG_SPRITE_H
#define PONG_SPRITE_H

#include "../TextureManager.h"

struct Sprite {
    SDL_Texture *texture;
    int height;
    int width;

    explicit Sprite(SDL_Renderer *renderer, const char *path) : texture{}, height{}, width{} {
        texture = TextureManager::LoadTexture(renderer, path);
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    }
};

#endif //PONG_SPRITE_H
