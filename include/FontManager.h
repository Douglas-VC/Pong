#ifndef PONG_FONTMANAGER_H
#define PONG_FONTMANAGER_H

#include <SDL2/SDL_ttf.h>
#include <unordered_map>
#include <string>

class FontManager {
public:
    SDL_Renderer *renderer;
    std::unordered_map<std::string, TTF_Font*> fonts;

    FontManager();
    ~FontManager();

    void loadFont(const std::string& fontName, const std::string& filePath, int fontSize);
    SDL_Texture* getTextTexture(const std::string& fontName, const std::string& text, SDL_Color color);
};

#endif //PONG_FONTMANAGER_H
