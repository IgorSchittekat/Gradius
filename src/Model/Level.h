#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H
#pragma once

#include <vector>
#include "Ship.h"
#include "../View/Window.h"
#include "../Utils/json.hpp"
#include "../Utils/Vec2.h"

namespace view {
    class EntityObserver;
}

namespace model {
    /**
     * @enum LevelStatus to indicate the status of the Level
     */
    enum class Levelstatus { PLAYING, VICTORY, GAMEOVER };

    class Level {
    public:
        /**
         * @brief Update all Entities and remove colliding entities
         */
        void update();

        /**
         * @brief Move the Ship
         * @param dir Direction to move the Ship in
         */
        void moveShip(util::Vec2d dir);

        /**
         * @brief Fire a bullet from the ship if possible
         */
        void fireShip();

        /**
         * @brief Add observer to list of observers
         * @param observer : Observer to be added
         */
        void addObserver(const std::shared_ptr<view::Window>& observer);

        /**
         * @brief Load all Data for the Level
         * @param data : Data to be loaded in
         */
        void setUp(nlohmann::json data);

        /**
         * @brief Returns the status of the Level
         * @return Status of the Level
         */
        Levelstatus getStatus();

    private:
        /**
         * @brief Set the Ship
         * @param ship : Ship to be set
         */
        void setShip(std::shared_ptr<Ship> ship);

        /**
         * @brief Add an Entity to list of all Entities
         * @param entity : Entity to be added
         */
        void addEntity(std::shared_ptr<Entity>& entity);

        /**
         * @brief notifies all observers if something happened with the entity
         * @param entity : entity that gets observed
         * @param what : notification of what happened
         */
        void notify(const std::shared_ptr<Entity>& entity, Notification what);

        /**
         * @brief Remove Entities that are colliding
         */
        void removeCollidingEntities();

        /**
         * @brief Get all colliding Entities with a given Entity
         * @param entity : Entity to be checked
         * @return Colliding Entities with given Entity
         */
        std::vector<std::shared_ptr<Entity>> getColliding(const std::shared_ptr<Entity>& entity);

    private:
        /**
         * @brief List of all Entities
         */
        std::vector<std::shared_ptr<Entity>> mEntities;
        /**
         * @brief Ship
         */
        std::shared_ptr<Ship> mShip;
        /**
         * @brief Speed of all bullets
         */
        double mBulletSpeed;
        /**
         * @briefList of all Observers
         */
        std::vector<std::shared_ptr<view::Window>> mObservers;
    };

} // namespace model


#endif //GRADIUS_LEVEL_H
