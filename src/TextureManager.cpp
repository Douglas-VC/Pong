#include <iostream>
#include <SDL_image.h>

#include "../include/TextureManager.h"
#include "../include/Game.h"

SDL_Texture *TextureManager::LoadTexture(const char *filename) {
    SDL_Texture *texture = IMG_LoadTexture(Game::renderer, filename);

    if (!texture) {
        std::cerr << "Failed to create texture from file: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect srcRect, SDL_Rect targetRect) {
    SDL_RenderCopy(Game::renderer, tex, &srcRect, &targetRect);
}
