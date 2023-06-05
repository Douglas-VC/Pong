#include "../include/SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "ERROR: Unable to initialize Audio Mixer library: " << SDL_GetError() << std::endl;
    }
    std::cout << "SDL Audio Mixer library loaded!" << std::endl;
}

SoundManager::~SoundManager() {
    for (const auto& sound : sounds)
        if (sound.second)
            Mix_FreeChunk(sound.second);
    Mix_CloseAudio();
}

void SoundManager::loadSound(const std::string& filename, const std::string& soundName) {
    Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
    if (!sound) {
        std::cerr << "Failed to load sound: " << Mix_GetError() << std::endl;
    }
    sounds[soundName] = sound;
}

void SoundManager::playSound(const std::string& soundName) {
    auto it = sounds.find(soundName);
    if (it != sounds.end()) {
        Mix_PlayChannel(-1, it->second, 0);
    } else {
        std::cerr << "Sound not found: " << soundName << std::endl;
    }
}