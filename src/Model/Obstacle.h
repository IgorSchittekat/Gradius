#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H
#pragma once

#include "Entity.h"

namespace model {

    class Obstacle : public Entity {
    public:
        Obstacle(double x, double y, double speed, bool border);
        bool isBorder() { return mBorder; }

        Notification update() override;

        Notification move(Direction dir) override;

    private:
        bool mBorder;

    };

}

#endif //GRADIUS_OBSTACLE_H
