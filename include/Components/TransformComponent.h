#ifndef PONG_TRANSFORMCOMPONENT_H
#define PONG_TRANSFORMCOMPONENT_H

#include "../ECS.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;
    float speed;

    int height;
    int width;
    int scale;

    TransformComponent() : position{}, velocity{}, speed{}, height{}, width{}, scale{1} {};
    TransformComponent(float x, float y) : position{x, y}, velocity{}, speed{}, height{}, width{}, scale{1} {};
    TransformComponent(float x, float y, int scale) : position{x, y}, velocity{}, speed{}, height{}, width{}, scale{scale} {};

    void update(float deltaTime) override {
        position += velocity * speed;
    }
};

#endif //PONG_TRANSFORMCOMPONENT_H
