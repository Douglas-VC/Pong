#ifndef PONG_SCORE_H
#define PONG_SCORE_H

#include <SDL2/SDL.h>
#include "../FontManager.h"

struct Score {
public:
    int score;
    SDL_Rect textPosition;
    SDL_Color textColor;
    SDL_Texture *textTexture;

    Score(FontManager *fontManager, const std::string& fontName, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) : score{}, textPosition{x, y,0,0}, textColor{r, g, b, a} {
        textTexture = fontManager->getTextTexture(fontName, "0", textColor);
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textPosition.w, &textPosition.h);
    };
};

#endif //PONG_SCORE_H
