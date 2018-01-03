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
        /**
         * @brief Constructor
         * @param texture : Texture of the sprite
         */
        explicit EntityObserver(const sf::Texture& texture);

        /**
         * @brief draw the sprite on the window
         * @param wnd : Window to draw the sprite on
         */
        void draw(sf::RenderWindow& wnd);

        /**
         * @brief update the Observer
         * @param entity : Entity that has changed
         * @param what : Notification of what happened
         */
        void update(const model::Entity* entity, model::Notification what);

    private:
        /**
         * @brief Sprite
         */
        sf::Sprite mSprite;
    };


} // namespace view

#endif //GRADIUS_OBSERVER_H
