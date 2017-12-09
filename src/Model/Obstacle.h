#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H
#pragma once

#include "Entity.h"

namespace model {

    class Obstacle : public Entity {
    public:
        Obstacle(double x, double y, double speed, bool border);
        bool isBorder() { return m_border; }

        Notification update() override;

        Notification move(Direction dir) override;

    private:
        bool m_border;

    };

}

#endif //GRADIUS_OBSTACLE_H
