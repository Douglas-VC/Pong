#ifndef PONG_RENDERSYSTEM_H
#define PONG_RENDERSYSTEM_H

#include "../../entt/entt.hpp"
#include "../TextureManager.h"

class RenderSystem {
public:
    RenderSystem() = default;
    ~RenderSystem() = default;

    void render(SDL_Renderer *renderer, entt::registry& registry);
};

#endif //PONG_RENDERSYSTEM_H
