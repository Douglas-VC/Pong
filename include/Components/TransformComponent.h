#ifndef PONG_TRANSFORMCOMPONENT_H
#define PONG_TRANSFORMCOMPONENT_H

#include "../ECS.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;
    float speed;

    TransformComponent() : position{}, velocity{}, speed{} {};
    TransformComponent(float x, float y) : position{x, y} {};

    void update(float deltaTime) override {
        position += velocity * speed;
    }
};

#endif //PONG_TRANSFORMCOMPONENT_H
