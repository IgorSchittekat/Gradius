#include "Enemy.h"

namespace model {

    Enemy::Enemy(double x, double y, double speed) :
            Entity(x, y, 0.4, 0.4, speed),
            m_timeUntillNextShot(20) {
        m_dir = Direction::UP;
    }

    Notification Enemy::update() {
        m_timeUntillNextShot--;
        if (m_y <= -2)
            m_dir = Direction::DOWN;
        else if (m_y >= 2)
            m_dir = Direction::UP;
        return move(m_dir);
    }

    bool Enemy::canFire() {
        if (m_timeUntillNextShot <= 0) {
            m_timeUntillNextShot = 20;
            return true;
        }
        return false;
    }


}