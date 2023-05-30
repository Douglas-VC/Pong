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
using Group = std::size_t;

inline ComponentID getUniqueComponentID() noexcept {
    static ComponentID lastID {0u};
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

constexpr std::size_t maxGroups {32};
using GroupBitset = std::bitset<maxGroups>;

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
    Manager& manager;

    bool active;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray{};
    ComponentBitset componentBitset;

    GroupBitset groupBitset;

public:
    Entity(Manager& mManager) : manager(mManager), active{true} {}

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

    [[nodiscard]] bool hasGroup(Group mGroup) const noexcept {
        return groupBitset[mGroup];
    }

    void addGroup(Group mGroup) noexcept;

    void delGroup(Group mGroup) noexcept {
        groupBitset[mGroup] = false;
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
    std::array<std::vector<Entity*>, maxGroups> groupedEntities;

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
        for(auto i(0u); i < maxGroups; ++i) {
            auto& group(groupedEntities[i]);

            group.erase(std::remove_if(std::begin(group), std::end(group),
                            [i](Entity* mEntity){
                                return !mEntity->isActive() || !mEntity->hasGroup(i);
                            }), std::end(group));
        }

        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                      [](const std::unique_ptr<Entity> &mEntity){ return !mEntity->isActive();}),
                       std::end(entities));
    }

    void addToGroup(Entity* mEntity, Group mGroup) {
        groupedEntities[mGroup].emplace_back(mEntity);
    }

    std::vector<Entity*>& getEntitiesByGroup(Group mGroup) {
        return groupedEntities[mGroup];
    }

    Entity &addEntity() {
        Entity* e {new Entity{*this}};
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};

void Entity::addGroup(Group mGroup) noexcept {
    groupBitset[mGroup] = true;
    manager.addToGroup(this, mGroup);
}

#endif //PONG_ECS_H
