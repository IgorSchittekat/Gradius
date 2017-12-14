#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H
#pragma once

#include "Entity.h"

namespace model {

    class Ship : public Entity {
    public:
        explicit Ship(int lives, double speed);

        bool canFire() override;
        Notification move(util::Vec2d dir) override;
        Notification update() override;
        bool hit(int count);
        bool isAlive() { return mLives > 0; }
        int getLives() const;
    private:
        int mLives;
        int mTimeUntilNextShot;
        int mTimeInvincible;
    };

}

#endif //GRADIUS_SHIP_H
