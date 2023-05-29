cmake_minimum_required(VERSION 3.24)
project(Pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(Pong src/main.cpp src/Game.cpp include/Game.h src/TextureManager.cpp include/TextureManager.h include/ECS.h include/Components/TransformComponent.h include/Components/SpriteComponent.h src/Vector2D.cpp include/Vector2D.h include/Components/ColliderComponent.h include/Components/WindowBoundComponent.h)

target_link_libraries(Pong ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})