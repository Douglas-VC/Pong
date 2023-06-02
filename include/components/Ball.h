#ifndef PONG_BALL_H
#define PONG_BALL_H

struct Ball {
    float velX;
    float velY;
    float minVel;
    float maxVel;
    int immunityTicks;

    Ball(float vx, float vy, float minv, float maxv) : velX{vx}, velY{vy}, minVel{minv}, maxVel{maxv}, immunityTicks{} {};
};

#endif //PONG_BALL_H
