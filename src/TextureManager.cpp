#include <iostream>
#include <SDL_image.h>

#include "../include/TextureManager.h"

SDL_Texture *TextureManager::LoadTexture(SDL_Renderer *renderer, const char *filename) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, filename);

    if (!texture) {
        std::cerr << "Failed to create texture from file: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}

void TextureManager::Draw(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect *srcRect, SDL_Rect *targetRect) {
    SDL_RenderCopy(renderer, tex, srcRect, targetRect);
}
