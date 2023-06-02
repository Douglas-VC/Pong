#ifndef PONG_BALL_H
#define PONG_BALL_H

struct Ball {
    float velX;
    float velY;

    Ball (float vx, float vy) : velX{vx}, velY{vy} {};
};

#endif //PONG_BALL_H
