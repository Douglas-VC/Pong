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

SDL_Texture* FontManager::getTextTexture(const std::string& fontName, const std::string& text, SDL_Color color) {
    SDL_Texture* textTexture;
    auto it = fonts.find(fontName);
    if (it != fonts.end()) {
        TTF_Font* font = it->second;
        SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
        if (!textSurface) {
            std::cerr << "Error creating text surface: " << TTF_GetError() << std::endl;
        } else {
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if(!textTexture) {
                std::cerr << "Error creating text texture: " << TTF_GetError() << std::endl;
            }

            SDL_FreeSurface(textSurface);
        }
    } else {
        std::cerr << "Font " << fontName << " not found." << std::endl;
    }

    return textTexture;
}