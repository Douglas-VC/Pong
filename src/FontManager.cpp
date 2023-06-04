#include "../include/FontManager.h"
#include <iostream>

FontManager::FontManager() {
    if (TTF_Init() == -1) {
        std::cerr << "ERROR: Unable to initialize TTF library: " << SDL_GetError() << std::endl;
        return;
    }
    std::cout << "SDL TTF library loaded!" << std::endl;
}

FontManager::~FontManager() {
    for (const auto& font : fonts)
        if (font.second)
            TTF_CloseFont(font.second);
    TTF_Quit();
}

void FontManager::loadFont(const std::string& fontName, const std::string& filePath, int fontSize) {
    fonts[fontName] = TTF_OpenFont(filePath.c_str(), fontSize);
    if (fonts[fontName] == nullptr) {
        std::cerr << "Error loading font " << fontName << ": " << TTF_GetError() << std::endl;
    }
}