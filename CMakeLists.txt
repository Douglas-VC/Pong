cmake_minimum_required(VERSION 3.24)
project(Pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(Pong src/main.cpp src/Game.cpp include/Game.h src/TextureManager.cpp include/TextureManager.h src/Vector2D.cpp include/Vector2D.h entt/entt.hpp src/Window.cpp include/Window.h include/components/Transform.h include/components/Sprite.h include/components/Collider.h include/systems/RenderSystem.cpp include/systems/RenderSystem.h include/events/KeyDown.h include/events/KeyUp.h include/systems/MovementSystem.cpp include/systems/MovementSystem.h include/components/Player.h include/components/Ball.h include/systems/ColliderSystem.cpp include/systems/ColliderSystem.h include/Random.h)

target_link_libraries(Pong ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})