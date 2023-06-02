#ifndef PONG_BALL_H
#define PONG_BALL_H

struct Ball {
    float velX;
    float velY;
    int immunityTicks;

    Ball(float vx, float vy) : velX{vx}, velY{vy}, immunityTicks{} {};
};

#endif //PONG_BALL_H
