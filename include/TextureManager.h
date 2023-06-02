#ifndef PONG_TEXTUREMANAGER_H
#define PONG_TEXTUREMANAGER_H
#include <SDL2/SDL.h>

class TextureManager {
public:
    static SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *filename);
    static void Draw(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect *srcRect, SDL_Rect *targetRect);
};

#endif //PONG_TEXTUREMANAGER_H