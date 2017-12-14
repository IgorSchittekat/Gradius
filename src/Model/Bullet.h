#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H
#pragma once

#include "Entity.h"

namespace model {
    class Level;

    class Bullet : public Entity {
    public:
        /**
         * @brief constructoe
         * @param firingEntity : entity that fires the bullet
         * @param speed : speed of the bullet
         * @param friendly : friendliness of the bullet
         */
        Bullet(const std::shared_ptr<Entity>& firingEntity, double speed, bool friendly);

        /**
         * @brief move the bullet
         * @param Dir : direction to move the bullet
         * @return notification of what happened exactly
         */
        Notification move(util::Vec2d dir) override;

        /**
         * @brief updates the bullet
         * @return notification of what happened exactly
         */
        Notification update() override;

        bool isFriendly();

    private:
        bool mFriendly;
    };

}

#endif //GRADIUS_BULLET_H
