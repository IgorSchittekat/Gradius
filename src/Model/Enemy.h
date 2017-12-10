#ifndef GRADIUS_ENEMY_H
#define GRADIUS_ENEMY_H
#pragma once

#include "Entity.h"

namespace model {

    class Level;

    class Enemy : public Entity {
    public:
        /**
         * @brief Constructor
         * @param x : x-coordinate of the enemy
         * @param y : y-coordinate of the enemy
         * @param speed : speed of the enemy
         * @param type : type of the enemy
         */
        Enemy(double x, double y, double speed, const std::string& type);

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
        Direction mDir;
        int mTimeUntilNextShot;
        std::string mType;
    };

}

#endif //GRADIUS_ENEMY_H
