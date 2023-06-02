#ifndef PONG_COLLIDER_H
#define PONG_COLLIDER_H

#include <SDL2/SDL.h>
#include <utility>

struct Collider {
public:
    SDL_Rect collider;
    std::string tag;

    explicit Collider(std::string t) : tag{std::move(t)}, collider{} {};
};

#endif //PONG_COLLIDER_H
