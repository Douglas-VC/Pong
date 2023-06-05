#ifndef PONG_SOUNDMANAGER_H
#define PONG_SOUNDMANAGER_H

#include <unordered_map>
#include <string>
#include <SDL2/SDL_mixer.h>

class SoundManager {
public:
    std::unordered_map<std::string, Mix_Chunk*> sounds;

    SoundManager();
    ~SoundManager();

    void loadSound(const std::string& filename, const std::string& soundName);
    void playSound(const std::string& soundName);
};

#endif //PONG_SOUNDMANAGER_H
