#ifndef PONG_AISYSTEM_H
#define PONG_AISYSTEM_H

#include "../../entt/entt.hpp"
#include "../Window.h"

class AISystem {
public:
    AISystem() = default;
    ~AISystem() = default;

    void update(Window &window, entt::registry& registry);
};

#endif //PONG_AISYSTEM_H
