#include "../include/TextureManager.h"
#include <iostream>
#include <SDL_image.h>

SDL_Texture *TextureManager::LoadTexture(const char *filename, SDL_Renderer *renderer) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, filename);

    if (!texture) {
        std::cerr << "Failed to create texture from file: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}
