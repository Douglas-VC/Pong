#ifndef PONG_WINLOSSSCREEN_H
#define PONG_WINLOSSSCREEN_H

#include "../../entt/entt.hpp"
#include "../FontManager.h"
#include "../Window.h"

class WinLossScreen {
    public:
        WinLossScreen() = default;
        ~WinLossScreen() = default;

        static void displayEndScreen(const std::string& winner, FontManager *fontManager, Window &window, entt::registry& registry);
};


#endif //PONG_WINLOSSSCREEN_H
