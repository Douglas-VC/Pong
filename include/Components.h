#ifndef PONG_COMPONENTS_H
#define PONG_COMPONENTS_H

#include "ECS.h"

class Position : public Component {
private:
    int xPos;
    int yPos;

public:
    Position() : xPos{}, yPos{} {};
    Position(int x, int y) : xPos{x}, yPos{y} {};

    [[nodiscard]] int x() const noexcept {
        return xPos;
    }
    [[nodiscard]] int y() const noexcept {
        return yPos;
    }

    void setPos(int x, int y) {
        xPos = x;
        yPos = y;
    }
};

#endif //PONG_COMPONENTS_H
