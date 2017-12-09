#include <iostream>
#include "Ship.h"

namespace model {

    Ship::Ship(int lives, double speed) :
            Entity(-3, 0, 1, 0.5, speed),
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
        m_timeUntillNextShot--;
        return Notification::NONE;
    }

    void Ship::hit(int count) {
        m_lives -= count;
    }


}