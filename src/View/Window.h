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
        /**
         * @brief Constructor
         * @param width : Width of the window
         * @param height : Height of the window
         * @param title : title of the window
         * @param background : file with background texture
         */
        Window(unsigned int width, unsigned int height, const std::string &title, const std::string& background);

        /**
         * @brief Deleted Copy Constructor
         */
        Window(const Window& rhs) = delete;

        /**
         * @brief Draw the Entities on the screen
         */
        void drawWindow();

        /**
         * @brief Check if the window is open
         * @return bool if the window is open
         */
        bool isOpen();

        /**
         * @brief Draw the victory image
         */
        void drawVictory();

        /**
         * @brief Draw the game over image
         */
        void drawGameOver();

        /**
         * @brief Add EntityObserver to the list of EntitiesRepresentations
         * @param entityObserver: Entity to be added
         */
        void addEntityObserver(const std::weak_ptr<EntityObserver>& entityObserver);

        /**
         * @brief Add a texture to the textures
         * @param name : Name of the texture
         * @param fileName : File of the Texture
         */
        void addTexture(const std::string& name, const std::string& fileName);

        /**
         * @brief Load textures from data
         * @param data : data with texturefiles
         */
        void loadTextures(nlohmann::json data);

        /**
         * @brief Update the observer
         * @param entity : Entity that has changed
         * @param what : Notification of what happened
         */
        void update(const std::shared_ptr<model::Entity>& entity, model::Notification what);

    private:
        /**
         * @brief Draw the Hearts on the window
         */
        void drawHearts();

        /**
         * @brief Draw the background on the winow
         */
        void drawBackground();

    private:
        /**
         * @brief Window
         */
        std::unique_ptr<sf::RenderWindow> mWnd;
        /**
         * @brief Strite for the background
         */
        sf::Sprite mBackground;
        /**
         * @brief list of all EntityRepresentations
         */
        std::vector<std::weak_ptr<EntityObserver>> mEntities;
        /**
         * @brief map of all Textures
         */
        std::map<std::string, std::shared_ptr<sf::Texture>> mTextures;
        /**
         * @brief Total amount of hearts to be displayed
         */
        int mHearts;
    };

}


#endif //GRADIUS_WORLD_H
