#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H
#pragma once

#include "Entity.h"

namespace model {

    class Obstacle : public Entity {
    public:
        /**
         * @brief Constructor
         * @param position : Position of the Obstacle
         * @param speed : Speed of the Obstacle
         * @param border : Indicates if the Obstacle is a border or not
         */
        Obstacle(util::Vec2d position, double speed, bool border);

        /**
         * @brief Returns if it is a border or not
         * @return bool is it is a border or not
         */
        bool isBorder() { return mBorder; }

        /**
         * @brief Update the Obstacle
         * @return Notification of what happened
         */
        Notification update() override;

        /**
         * @brief move the obstacle
         * @param dir : Direction to be moved in
         * @return Notification of what happened
         */
        Notification move(util::Vec2d dir) override;

    private:
        /**
         * @brief Indicates if it is a border or not
         */
        bool mBorder;
    };

} // namespace model

#endif //GRADIUS_OBSTACLE_H
