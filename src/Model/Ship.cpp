#include "Ship.h"

namespace model {

    Ship::Ship(int lives, double speed) :
            Entity(-3, 0, 0.5, 0.25, speed),
            m_lives(lives),
            m_timeUntillNextShot(0){
    }

    bool Ship::canFire() {
        if (m_timeUntillNextShot < 0) {
            m_timeUntillNextShot = 20;
            return true;
        }
        return false;
    }

    Notification Ship::update() {
        return Notification::NONE;
    }


}