#ifndef GRADIUS_WORLD_H
#define GRADIUS_WORLD_H
#pragma once

#include <SFML/Graphics.hpp>
#include "EntityObserver.h"
#include "../Controller/json.hpp"
#include <map>
#include <memory>

namespace model {
    class Entity;
    enum class Notification;
}

namespace view {

    class EntityObserver;

    class Window {
    public:
        Window(unsigned int width, unsigned int height, const std::string &title, const std::string& background);
        Window(const Window& rhs) = delete;
        void drawWindow();

        bool isOpen();

        void drawBackground();

        sf::Text getFPS();

        void addEntityObserver(const std::weak_ptr<EntityObserver>& entityObserver);

        void addTexture(const std::string& name, const std::string& fileName);

        std::shared_ptr<sf::Texture> getTexture(const std::string& name);

        void deleteObservers();

        void loadTextures(nlohmann::json data);

        std::shared_ptr<EntityObserver> update(const std::shared_ptr<model::Entity>& entity, model::Notification what);

    private:
        std::unique_ptr<sf::RenderWindow> m_wnd;
        sf::Texture m_backgroundTexture;
        sf::Sprite m_background;
        sf::Font font;
        std::vector<std::weak_ptr<EntityObserver>> m_entities;
        std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;
    };

}


#endif //GRADIUS_WORLD_H
