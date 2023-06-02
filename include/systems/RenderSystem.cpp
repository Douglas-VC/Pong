#include "RenderSystem.h"
#include "../../entt/entt.hpp"
#include "../components/Transform.h"
#include "../components/Sprite.h"

void RenderSystem::render(SDL_Renderer *renderer, entt::registry& registry) {
    auto view = registry.view<Sprite, Transform>();
    for(auto entity: view) {
        auto &transform = view.get<Transform>(entity);
        auto &sprite = view.get<Sprite>(entity);

        SDL_Rect draw_rect {static_cast<int>(transform.position.x), static_cast<int>(transform.position.y), sprite.width, sprite.height};
        SDL_RenderCopy(renderer, sprite.texture, {}, &draw_rect);
    }
}
