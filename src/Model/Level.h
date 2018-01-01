#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H
#pragma once

#include <vector>
#include <set>
#include "Ship.h"
#include "../View/Window.h"
#include "../Utils/json.hpp"
#include "../Utils/Vec2.h"

namespace view {
    class EntityObserver;
}

namespace model {

    enum class Levelstatus { PLAYING, VICTORY, GAMEOVER };

    class Level {
    public:

        void update();

        void moveShip(util::Vec2d dir);

        void fireShip();

        void addEntity(std::shared_ptr<Entity>& entity);

        void setShip(std::shared_ptr<Ship> ship);

        std::vector<std::shared_ptr<Entity>> isColliding(const std::shared_ptr<Entity>& entity);

        void addObserver(const std::shared_ptr<view::Window>& observer);

        /**
         * @brief notifies all observers if something happened with the entity
         * @param entity : entity that gets observed
         * @param what : notification of what happened
         */
        void notify(const std::shared_ptr<Entity>& entity, Notification what);

        void setUp(nlohmann::json data);

        Levelstatus getStatus();

    private:
        void removeCollidingEntities();
    private:
        std::vector<std::shared_ptr<Entity>> mEntities;
        std::shared_ptr<Ship> mShip;
        double mBulletSpeed;
        std::vector<std::shared_ptr<view::Window>> mObservers;
    };

} // namespace model


#endif //GRADIUS_LEVEL_H
