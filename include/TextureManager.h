#ifndef PONG_TEXTUREMANAGER_H
#define PONG_TEXTUREMANAGER_H
#include <SDL2/SDL.h>

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *filename);
};

#endif //PONG_TEXTUREMANAGER_H