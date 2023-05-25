#ifndef PONG_TEXTUREMANAGER_H
#define PONG_TEXTUREMANAGER_H
#include <SDL2/SDL.h>

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *filename);
    static void Draw(SDL_Texture *tex, SDL_Rect srcRect, SDL_Rect targetRect);
};

#endif //PONG_TEXTUREMANAGER_H