#ifndef PONG_WINDOWBOUNDCOMPONENT_H
#define PONG_WINDOWBOUNDCOMPONENT_H

#include "../ECS.h"

class WindowBoundComponent : public Component {
public:
    int wHeight;
    int wWidth;

    explicit WindowBoundComponent(int h, int w) : wHeight{h}, wWidth{w} {};
};

#endif //PONG_WINDOWBOUNDCOMPONENT_H
