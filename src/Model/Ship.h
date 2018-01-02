#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H
#pragma once

#include "Entity.h"

namespace model {

    class Ship : public Entity {
    public:
        /**
         * @brief Constructor
         * @param lives : Lives of the Ship
         * @param speed : Speed of the Ship
         */
        Ship(int lives, double speed);

        /**
         * @brief indicates if the Ship can fire
         * @return bool if the Ship can fire
         */
        bool canFire() override;

        /**
         * @brief Move the ship
         * @param dir : Direction to move in
         * @return Notification of what happened
         */
        Notification move(util::Vec2d dir) override;

        /**
         * @brief Update the time untill the next shot and time that the Ship is invincible
         * @return Notification::NONE
         */
        Notification update() override;

        /**
         * @brief Decrease lives if Ship is not invincible
         * @param count : Amount to increase the lives
         * @return bool if the lives where decreased
         */
        bool hit(int count);

        /**
         * @brief Indicates if the Ship is still alive
         * @return bool is lives > 0
         */
        bool isAlive() { return mLives > 0; }

        /**
         * @brief Get amound of lives
         * @return amound of lives
         */
        int getLives() const;

    private:
        /**
         * @brief lives
         */
        int mLives;
        /**
         * @brief delay until next shot
         */
        int mTimeUntilNextShot;
        /**
         * @brief delay when hit
         */
        int mTimeInvincible;
    };

} // namespace model

#endif //GRADIUS_SHIP_H
