#include <iostream>
#include "Bullet.h"


namespace model {

    Bullet::Bullet(const std::shared_ptr<model::Entity>& firingEntity, double speed, bool friendly) :
            Entity(util::Vec2d(firingEntity->getLocation().getX(), firingEntity->getLocation().getY()), 0.5, 0.25, speed),
            mFriendly(friendly) {
    }

    Notification Bullet::move(util::Vec2d dir) {
        mPosition += dir * mSpeed;
        if (dir == util::Vec2d(-1, 0)) {
            if (mPosition.getX() <= -4.5) {
                notify(Notification::DELETED);
                return Notification::DELETED;
            }
        }
        else if (dir == util::Vec2d(1, 0)) {
            if (mPosition.getX() >= 4) {
                notify(Notification::DELETED);
                return Notification::DELETED;
            }
        }
        notify(Notification::MOVED);
        return Notification::MOVED;
    }

    Notification Bullet::update() {
        if (mFriendly)
            return move(util::Vec2d(1, 0));
        else
            return move(util::Vec2d(-1, 0));
    }

    bool Bullet::isFriendly() {
        return mFriendly;
    }

} // namespace model

