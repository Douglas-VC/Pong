#ifndef PONG_FONTMANAGER_H
#define PONG_FONTMANAGER_H

#include <SDL2/SDL_ttf.h>
#include <unordered_map>
#include <string>

class FontManager {
private:
    std::unordered_map<std::string, TTF_Font*> fonts;

public:
    FontManager();
    ~FontManager();

    void loadFont(const std::string& fontName, const std::string& filePath, int fontSize);
};

#endif //PONG_FONTMANAGER_H
