#ifndef GRADIUS_ENEMY_H
#define GRADIUS_ENEMY_H
#pragma once

#include "Entity.h"

namespace model {

    class Level;

    class Enemy : public Entity {
    public:
        Enemy(double x, double y, double speed);
        Notification update() override;
        bool canFire() override;

    private:
        Direction m_dir;
        int m_timeUntillNextShot;

    };

}

#endif //GRADIUS_ENEMY_H
