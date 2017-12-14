#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H
#pragma once

#include "Entity.h"

namespace model {

    class Obstacle : public Entity {
    public:
        Obstacle(util::Vec2d position, double speed, bool border);
        bool isBorder() { return mBorder; }

        Notification update() override;

        Notification move(util::Vec2d dir) override;

    private:
        bool mBorder;

    };

}

#endif //GRADIUS_OBSTACLE_H
