#include "../include/GameObject.h"
#include "../include/TextureManager.h"
#include "../include/Game.h"

GameObject::GameObject(const char *filename, int x, int y) : xPos{x}, yPos{y}, width{}, height{} {
    objTexture = TextureManager::LoadTexture(filename);
    SDL_QueryTexture(objTexture, nullptr, nullptr, &width, &height);
}

GameObject::~GameObject() {
    if (objTexture)
        SDL_DestroyTexture(objTexture);
}

void GameObject::update() {

}

void GameObject::render() {
    SDL_Rect dstRect = { xPos, yPos, width, height};
    SDL_RenderCopy(Game::renderer, objTexture, nullptr, &dstRect);
}
