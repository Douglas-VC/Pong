#ifndef PONG_COLLIDERSYSTEM_H
#define PONG_COLLIDERSYSTEM_H

#include "../../entt/entt.hpp"

class ColliderSystem {
public:
    ColliderSystem() = default;
    ~ColliderSystem() = default;

    struct CollisionHolder {
        entt::entity player;
        entt::entity ai;
        entt::entity ball;

        entt::registry* registry;
    };


    void update(CollisionHolder &collisionHolder);
};

#endif //PONG_COLLIDERSYSTEM_H
