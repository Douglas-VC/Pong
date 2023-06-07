#ifndef PONG_BALL_H
#define PONG_BALL_H

struct Ball {
    float velX;
    float velY;
    float minVel;
    float maxVel;
    int immunityTicks;

    Ball(float vx, float vy, float minV, float maxV) : velX{vx}, velY{vy}, minVel{minV}, maxVel{maxV}, immunityTicks{} {};
};

#endif //PONG_BALL_H
