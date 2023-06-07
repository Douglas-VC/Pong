#include "AISystem.h"
#include "../components/Transform.h"
#include "../components/Ball.h"
#include "../components/AI.h"
#include "../components/Sprite.h"

void AISystem::update(Window &window, entt::registry& registry) {
    auto aiView = registry.view<AI, Transform, Sprite>();
    auto ballView = registry.view<Ball, Transform, Sprite>();
    for(auto entity1: aiView) {
        auto &aiTransform = aiView.get<Transform>(entity1);
        auto &aiSprite = aiView.get<Sprite>(entity1);
        for(auto entity2: ballView) {
            auto &ballTransform = aiView.get<Transform>(entity2);
            auto &ballSprite = aiView.get<Sprite>(entity2);
//            aiTransform.position.y = (ballTransform.position.y + ballSprite.height / 2.0f) - (aiSprite.height / 2.0f);

            double distDiff = (aiTransform.position.y + aiSprite.height / 2.0f) - (ballTransform.position.y + ballSprite.height / 2.0f);
            if (distDiff < -8.0) {
                aiTransform.position.y += 6.0;
            } else if (distDiff > 8.0){
                aiTransform.position.y -= 6.0;
            }

            if (aiTransform.position.y < 0.0) {
                aiTransform.position.y = 0.0;
            } else if (aiTransform.position.y > static_cast<float>(window.height - aiSprite.height)) {
                aiTransform.position.y = static_cast<float>(window.height - aiSprite.height);
            }
        }
    }
};
