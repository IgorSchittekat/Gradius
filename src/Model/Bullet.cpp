#include <iostream>
#include "Bullet.h"


namespace model {

    Bullet::Bullet(const std::shared_ptr<model::Entity>& firingEntity, double speed) :
        Entity(firingEntity->getLocation().first, firingEntity->getLocation().second, 0.25, 0.125, speed) {
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
        return move(Direction::LEFT);
    }

} // namespace model

