#ifndef PONG_POSITIONCOMPONENT_H
#define PONG_POSITIONCOMPONENT_H

#include "../ECS.h"

class PositionComponent : public Component {
private:
    int xPos;
    int yPos;

public:
    PositionComponent() : xPos{}, yPos{} {};
    PositionComponent(int x, int y) : xPos{x}, yPos{y} {};

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

#endif //PONG_POSITIONCOMPONENT_H
