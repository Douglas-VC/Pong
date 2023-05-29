#ifndef PONG_TRANSFORMCOMPONENT_H
#define PONG_TRANSFORMCOMPONENT_H

#include "../ECS.h"
#include "../Vector2D.h"
#include "WindowBoundComponent.h"

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
    TransformComponent(float x, float y, int h, int w, int scale) : position{x, y}, velocity{}, speed{}, height{h}, width{w}, scale{scale} {};

    void update(float deltaTime) override {
        position += velocity * speed;
        if (entity->hasComponent<WindowBoundComponent>()) {
            if (position.x <= 0)
                position.x = 0;

            if (position.y <= 0)
                position.y = 0;

            if (position.x + width > entity->getComponent<WindowBoundComponent>().wWidth)
                position.x = entity->getComponent<WindowBoundComponent>().wWidth - width;

            if (position.y + height > entity->getComponent<WindowBoundComponent>().wHeight)
                position.y = entity->getComponent<WindowBoundComponent>().wHeight - height;
        }
    }
};

#endif //PONG_TRANSFORMCOMPONENT_H
