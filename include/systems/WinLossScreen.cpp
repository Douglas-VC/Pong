#include "WinLossScreen.h"
#include "../components/AI.h"
#include "../components/Score.h"
#include "../components/Transform.h"
#include "../components/Player.h"

void WinLossScreen::displayEndScreen(const std::string& winner, FontManager *fontManager, Window &window, entt::registry& registry) {
    SDL_RenderClear(window.getRenderer());

    SDL_Texture *winnerTitle = fontManager->getTextTexture("arial128", winner + " won!", {255, 255, 255, 255});
    SDL_Texture *helperMessage = fontManager->getTextTexture("arial32", "Press any key to play again", {255, 255, 255, 255});

    SDL_Rect winnerTitlePos;
    SDL_QueryTexture(winnerTitle, nullptr, nullptr, &winnerTitlePos.w, &winnerTitlePos.h);
    winnerTitlePos.x = window.width / 2 - winnerTitlePos.w / 2;
    winnerTitlePos.y = window.height / 2 - winnerTitlePos.h / 2;
    SDL_RenderCopy(window.getRenderer(), winnerTitle, {}, &winnerTitlePos);

    SDL_Rect helperMessagePos;
    SDL_QueryTexture(helperMessage, nullptr, nullptr, &helperMessagePos.w, &helperMessagePos.h);
    helperMessagePos.x = window.width / 2 - helperMessagePos.w / 2;
    helperMessagePos.y = window.height / 2 + 150;
    SDL_RenderCopy(window.getRenderer(), helperMessage, {}, &helperMessagePos);
    SDL_RenderPresent(window.getRenderer());

    auto playerScoreView = registry.view<Transform, Player, Score>();
    for(auto entity: playerScoreView) {
        auto &score = playerScoreView.get<Score>(entity);
        auto &transform = playerScoreView.get<Transform>(entity);
        score.score = 0;
        SDL_DestroyTexture(score.textTexture);
        score.textTexture = fontManager->getTextTexture("arial128", std::to_string(score.score), score.textColor);
        transform.position.y = window.height / 2 - 50;
    }

    auto AIScoreView = registry.view<Transform, AI, Score>();
    for(auto entity: AIScoreView) {
        auto &score = AIScoreView.get<Score>(entity);
        auto &transform = AIScoreView.get<Transform>(entity);
        score.score = 0;
        SDL_DestroyTexture(score.textTexture);
        score.textTexture = fontManager->getTextTexture("arial128", std::to_string(score.score), score.textColor);
        transform.position.y = window.height / 2 - 50;
    }

    SDL_Event event;
    bool buttonPressed {false};
    while (!buttonPressed) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                buttonPressed = true;
                break;
            }
        }
    }
}
