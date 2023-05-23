#ifndef PONG_GAMEOBJECT_H
#define PONG_GAMEOBJECT_H
#include <SDL2/SDL.h>

class GameObject {
private:
    SDL_Texture *objTexture;
    int xPos;
    int yPos;
    int width;
    int height;

public:
    GameObject(const char *filename, int x, int y);
    ~GameObject();

    void update();
    void render();
};

#endif //PONG_GAMEOBJECT_H
