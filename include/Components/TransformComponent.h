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

    TransformComponent() : position{}, velocity{}, speed{}, height{16}, width{16}, scale{1} {};
    TransformComponent(float x, float y) : position{x, y}, velocity{}, speed{}, height{16}, width{16}, scale{1} {};
    TransformComponent(float x, float y, int h, int w, int scale) : position{x, y}, velocity{}, speed{}, height{h}, width{w}, scale{scale} {};

    void update(float deltaTime) override {
        position += velocity * speed;
    }
};

#endif //PONG_TRANSFORMCOMPONENT_H
