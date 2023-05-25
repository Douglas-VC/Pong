#ifndef PONG_TRANSFORMCOMPONENT_H
#define PONG_TRANSFORMCOMPONENT_H

#include "../ECS.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;

    TransformComponent() : position{} {};
    TransformComponent(float x, float y) : position{x, y} {};
};

#endif //PONG_TRANSFORMCOMPONENT_H
