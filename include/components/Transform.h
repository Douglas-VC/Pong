#ifndef PONG_TRANSFORM_H
#define PONG_TRANSFORM_H

#include "../Vector2D.h"

struct Transform {
    Vector2D position;
    Vector2D velocity;
    float speed;

    Transform() : position{}, velocity{}, speed{} {};
    Transform(float x, float y) : position{x, y}, velocity{}, speed{} {};
    Transform(float x, float y, float spd) : position{x, y}, velocity{}, speed{spd} {};
    Transform(float x, float y, float vx, float vy, float spd) : position{x, y}, velocity{vx, vy}, speed{spd} {};
};

#endif //PONG_TRANSFORM_H
