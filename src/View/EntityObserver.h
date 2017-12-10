#ifndef GRADIUS_OBSERVER_H
#define GRADIUS_OBSERVER_H
#pragma once

#include "Window.h"
#include "../Model/Entity.h"

namespace model {
    class Entity;
    enum class Notification;

}

namespace view {

    class Window;

    class EntityObserver {
    public:

        EntityObserver(const std::shared_ptr<Window>& wnd, const std::string& textureFile, const std::string& type);

        EntityObserver(const std::shared_ptr<Window>& wnd, const std::string& type);

        EntityObserver(const sf::Texture& texture);

        EntityObserver(const EntityObserver &rhs);

        EntityObserver &operator=(const EntityObserver &rhs);

        ~EntityObserver();

        void draw(sf::RenderWindow& wnd);

        void update(const model::Entity* entity, model::Notification what);

    private:
        sf::IntRect mRect;
        sf::Sprite mSprite;
    };


} // namespace view

#endif //GRADIUS_OBSERVER_H
