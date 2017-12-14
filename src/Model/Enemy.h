#ifndef GRADIUS_ENEMY_H
#define GRADIUS_ENEMY_H
#pragma once

#include "Entity.h"

namespace model {

    class Enemy : public Entity {
    public:
        /**
         * @brief Constructor
         * @param x : x-coordinate of the enemy
         * @param y : y-coordinate of the enemy
         * @param speed : speed of the enemy
         * @param type : type of the enemy
         */
        Enemy(util::Vec2d position, double speed, std::string type);


        Notification move(util::Vec2d dir) override;

        /**
         * @brief updates the enemy
         * @return notification of what happened
         */
        Notification update() override;

        /**
         * @brief check is the enemy can fire
         * @return if the enemy can fire
         */
        bool canFire() override;

        std::string getType() const;

    private:
        util::Vec2d mDir;
        int mTimeUntilNextShot;
        std::string mType;
    };

}

#endif //GRADIUS_ENEMY_H
