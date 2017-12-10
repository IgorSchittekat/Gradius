#include <iostream>
#include "Ship.h"

namespace model {

    Ship::Ship(int lives, double speed) :
            Entity(-3, 0, 1, 0.5, speed),
            m_lives(lives),
            m_timeUntilNextShot(0){
    }

    bool Ship::canFire() {
        if (m_timeUntilNextShot < 0) {
            m_timeUntilNextShot = 20;
            return true;
        }
        return false;
    }

    Notification Ship::update() {
        m_timeUntilNextShot--;
        m_timeInvincible--;
        return Notification::NONE;
    }

    bool Ship::hit(int count) {
        if (m_timeInvincible < 0) {
            m_lives -= count;
            m_timeInvincible = 60;
            return true;
        }
        return false;
    }

    int Ship::getLives() const {
        return m_lives;
    }


}