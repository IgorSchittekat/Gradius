#include "Enemy.h"

namespace model {

    Enemy::Enemy(double x, double y, double speed, const std::string& type) :
            Entity(x, y, 0.8, 0.8, speed),
            m_timeUntilNextShot(18),
            m_type(type) {
        m_dir = Direction::UP;
    }

    Notification Enemy::update() {
        if (m_type == "shooting") {
            m_timeUntilNextShot--;
            if (m_y <= -2)
                m_dir = Direction::DOWN;
            else if (m_y >= 2)
                m_dir = Direction::UP;
            return move(m_dir);
        }
        else if (m_type == "flying") {
            m_dir = Direction::LEFT;
            return move(m_dir);
        }
    }

    bool Enemy::canFire() {
        if (m_timeUntilNextShot <= 0) {
            m_timeUntilNextShot = 80;
            return true;
        }
        return false;
    }

    std::string Enemy::getType() const {
        return m_type;
    }


}