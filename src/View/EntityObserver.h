#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H
#pragma once

#include "Window.h"
#include "../Model/Entity.h"

namespace model {
    class Entity;
}

namespace view {

    enum class Notification {CREATED, MOVED};

    class Window;

    class EntityObserver {
    public:

        explicit EntityObserver(const std::string& textureFile);

        EntityObserver(const EntityObserver &rhs);

        EntityObserver &operator=(const EntityObserver &rhs);

        ~EntityObserver();

        void draw(Window& wnd);

        void update(const model::Entity* entity, Notification what);

    private:
        unsigned int x;
        unsigned int y;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    };


} // namespace view

#endif //GRADIUS_OBSERVER_H
