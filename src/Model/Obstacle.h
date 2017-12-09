#ifndef GRADIUS_OBSTACLE_H
#define GRADIUS_OBSTACLE_H
#pragma once

#include "Entity.h"

namespace model {
    class Level;

    class Obstacle : public Entity {
    public:
        bool isMovable();
    private:
        bool movable;

    };

}

#endif //GRADIUS_OBSTACLE_H
