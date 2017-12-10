#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H
#pragma once

#include "Entity.h"

namespace model {

    class Ship : public Entity {
    public:
        explicit Ship(int lives, double speed);

        bool canFire() override;
        Notification update() override;
        bool hit(int count);
        bool isAlive() { return m_lives > 0; }
        int getLives() const;
    private:
        int m_lives;
        int m_timeUntilNextShot;
        int m_timeInvincible;
    };

}

#endif //GRADIUS_SHIP_H
