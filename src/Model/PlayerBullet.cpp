#include "PlayerBullet.h"

namespace model {

    PlayerBullet::PlayerBullet(const std::shared_ptr<Entity> &firingEntity, double speed) :
            Bullet(firingEntity, speed) {

    }

    Notification PlayerBullet::update() {
        return move(Direction::RIGHT);
    }



}