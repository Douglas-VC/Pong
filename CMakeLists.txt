cmake_minimum_required(VERSION 3.24)
project(Pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

add_executable(Pong src/main.cpp src/Game.cpp include/Game.h src/TextureManager.cpp include/TextureManager.h src/Vector2D.cpp include/Vector2D.h entt/entt.hpp src/Window.cpp include/Window.h include/components/Transform.h include/components/Sprite.h include/components/Collider.h include/systems/RenderSystem.cpp include/systems/RenderSystem.h include/events/KeyDown.h include/events/KeyUp.h include/systems/MovementSystem.cpp include/systems/MovementSystem.h include/components/Player.h include/components/Ball.h include/systems/CollisionSystem.cpp include/systems/CollisionSystem.h include/Random.h include/components/AI.h include/systems/AISystem.cpp include/systems/AISystem.h src/FontManager.cpp include/FontManager.h include/components/Score.h src/SoundManager.cpp include/SoundManager.h include/systems/WinLossScreen.cpp include/systems/WinLossScreen.h)

target_link_libraries(Pong ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES})