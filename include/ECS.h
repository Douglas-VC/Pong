#ifndef PONG_ECS_H
#define PONG_ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <cassert>
#include <type_traits>

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;

inline ComponentID getUniqueComponentID() noexcept {
    static ComponentID lastID {0};
    return lastID++;
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept {
    static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

    static ComponentID typeID {getUniqueComponentID()};
    return typeID;
}

constexpr std::size_t maxComponents {32};
using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
public:
    Entity *entity;

    virtual void init() {}

    virtual void update(float deltaTime) {}
    virtual void draw() {}

    virtual ~Component() {}
};

class Entity {
private:
    bool active {true};
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitset componentBitset;

public:
    void update(float deltaTime) {
        for(auto &c : components)
            c->update(deltaTime);
    }

    void draw() {
        for(auto &c : components)
            c->draw();
    }

    [[nodiscard]] bool isActive() const {
        return active;
    }

    void destroy() {
        active = false;
    }

    template <typename T>
    [[nodiscard]] bool hasComponent() const {
        return componentBitset[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs) {
        assert(!hasComponent<T>());

        T *c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr {c};
        components.emplace_back(std::move(uPtr));

        componentBitset[getComponentTypeID<T>()] = true;
        componentArray[getComponentTypeID<T>()] = c;

        c->init();

        return *c;
    }

    template <typename T>
    T& getComponent() const {
        assert(hasComponent<T>());
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void update(float deltaTime) {
        for(auto &e : entities)
            e->update(deltaTime);
    }
    void draw() {
        for(auto &e : entities)
            e->draw();
    }

    void refresh() {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                      [](const std::unique_ptr<Entity> &mEntity){ return !mEntity->isActive();}),
                       std::end(entities));
    }

    Entity &addEntity() {
        Entity* e {new Entity{}};
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};

#endif //PONG_ECS_H
