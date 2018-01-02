#include <iostream>
#include "Ship.h"

namespace model {

    Ship::Ship(int lives, double speed) :
            Entity(util::Vec2d(-3, 0), 1, 0.5, speed),
            mLives(lives),
            mTimeUntilNextShot(0),
            mTimeInvincible(0) {
    }

    bool Ship::canFire() {
        if (mTimeUntilNextShot < 0) {
            mTimeUntilNextShot = 20;
            return true;
        }
        return false;
    }

    Notification Ship::move(util::Vec2d dir) {
        if ((mPosition.getX() - mWidth / 2 + dir.getX() * mSpeed) >= -4
            && (mPosition.getX() + mWidth / 2 + dir.getX() * mSpeed) <= 4
            && (mPosition.getY() - mHeight / 2 + dir.getY() * mSpeed) >= -3
            && (mPosition.getY() + mHeight / 2 + dir.getY() * mSpeed) <= 3) {
            mPosition += dir * mSpeed;
        }
        notify(Notification::MOVED);
        return Notification::MOVED;
    }

    Notification Ship::update() {
        mTimeUntilNextShot--;
        mTimeInvincible--;
        return Notification::NONE;
    }

    bool Ship::hit(int count) {
        if (mTimeInvincible < 0) {
            mLives -= count;
            mTimeInvincible = 60;
            return true;
        }
        return false;
    }

    int Ship::getLives() const {
        return mLives;
    }

} // namespace model