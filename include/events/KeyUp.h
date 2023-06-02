#ifndef PONG_KEYUP_H
#define PONG_KEYUP_H

struct KeyUp {
    int keyCode = -1;

    inline KeyUp(int key_code) : keyCode(key_code) {};
};

#endif //PONG_KEYUP_H
