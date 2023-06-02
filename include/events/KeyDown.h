#ifndef PONG_KEYDOWN_H
#define PONG_KEYDOWN_H

struct KeyDown {
    int keyCode = -1;

    inline KeyDown(int key_code) : keyCode(key_code) {};
};

#endif //PONG_KEYDOWN_H
