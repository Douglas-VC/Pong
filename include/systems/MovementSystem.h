#ifndef PONG_MOVEMENTSYSTEM_H
#define PONG_MOVEMENTSYSTEM_H

#include "../../entt/entt.hpp"
#include "../components/Player.h"
#include "../events/KeyDown.h"
#include "../events/KeyUp.h"
#include "../Window.h"
#include "../FontManager.h"

class MovementSystem {
public:
    MovementSystem() = default;
    ~MovementSystem() = default;

    Player::MoveDirection playerMovement;

    void onKeyDown(const KeyDown& key_down) noexcept;
    void onKeyUp(const KeyUp& key_up) noexcept;
    void update(FontManager *fontManager,Window &window, entt::registry& registry);
};

#endif //PONG_MOVEMENTSYSTEM_H
