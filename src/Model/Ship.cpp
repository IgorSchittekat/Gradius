#include <iostream>
#include "Ship.h"

namespace model {

    Ship::Ship(int lives, double speed) :
            Entity(-3, 0, 1, 0.5, speed),
            mLives(lives),
            mTimeUntilNextShot(0){
    }

    bool Ship::canFire() {
        if (mTimeUntilNextShot < 0) {
            mTimeUntilNextShot = 20;
            return true;
        }
        return false;
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


}