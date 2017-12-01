#include "PlayerBullet.h"

namespace model {

    PlayerBullet::PlayerBullet(const std::shared_ptr<Entity> &firingEntity, double speed) :
            Bullet(firingEntity, speed) {

    }

    PlayerBullet &PlayerBullet::operator=(const PlayerBullet &rhs) {
        return *this;
    }

    PlayerBullet::~PlayerBullet() {
    }

    Notification PlayerBullet::move() {

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

    Notification PlayerBullet::update() {
        return move();
    }


}