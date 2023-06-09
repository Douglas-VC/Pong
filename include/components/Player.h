#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

struct Player {
    enum class MoveDirection : short {
        STOPPED,
        UP,
        DOWN
    };
    MoveDirection moveDirection = MoveDirection::STOPPED;
};

#endif //PONG_PLAYER_H
