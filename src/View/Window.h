#ifndef GRADIUS_WORLD_H
#define GRADIUS_WORLD_H
#pragma once

#include <SFML/Graphics.hpp>
#include "EntityObserver.h"
#include "../Utils/json.hpp"
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

        void addEntityObserver(const std::weak_ptr<EntityObserver>& entityObserver);

        void addTexture(const std::string& name, const std::string& fileName);

        void loadTextures(nlohmann::json data);

        std::shared_ptr<EntityObserver> update(const std::shared_ptr<model::Entity>& entity, model::Notification what);

    private:
        void drawHearts();

    private:
        std::unique_ptr<sf::RenderWindow> mWnd;
        sf::Texture mBackgroundTexture;
        sf::Sprite mBackground;
        std::vector<std::weak_ptr<EntityObserver>> mEntities;
        std::map<std::string, std::shared_ptr<sf::Texture>> mTextures;
        int mHearts;
    };

}


#endif //GRADIUS_WORLD_H
