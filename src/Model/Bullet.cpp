#include <iostream>
#include "Bullet.h"


namespace model {

    Bullet::Bullet(const std::shared_ptr<model::Entity>& firingEntity, double speed, bool friendly) :
            Entity(firingEntity->getLocation().first, firingEntity->getLocation().second, 0.5, 0.25, speed),
            m_friendly(friendly) {
    }

    Notification Bullet::move(Direction dir) {
        if (dir == Direction::LEFT) {
            if (m_x - m_speed - m_width / 2 >= -4) {
                m_x -= m_speed;
                notify(Notification::MOVED);
                return Notification::MOVED;
            }
            else {
                notify(Notification::DELETED);
                return Notification::DELETED;
            }
        }
        else if (dir == Direction::RIGHT) {
            if (m_x + m_speed + m_width / 2 <= 4) {
                m_x += m_speed;
                notify(Notification::MOVED);
                return Notification::MOVED;
            }
            else {
                notify(Notification::DELETED);
                return Notification::DELETED;
            }
        }
        else {
            return Notification::NONE;
        }
    }

    Notification Bullet::update() {
        if (m_friendly)
            return move(Direction::RIGHT);
        else
            return move(Direction::LEFT);
    }

    bool Bullet::isFriendly() {
        return m_friendly;
    }

} // namespace model

