#include <iostream>
#include "Bullet.h"


namespace model {

    Bullet::Bullet(const std::shared_ptr<model::Entity>& firingEntity, double speed, bool friendly) :
            Entity(firingEntity->getLocation().first, firingEntity->getLocation().second, 0.5, 0.25, speed),
            mFriendly(friendly) {
    }

    Notification Bullet::move(Direction dir) {
        if (dir == Direction::LEFT) {
            if (mX - mSpeed - mWidth / 2 >= -4) {
                mX -= mSpeed;
                notify(Notification::MOVED);
                return Notification::MOVED;
            }
            else {
                notify(Notification::DELETED);
                return Notification::DELETED;
            }
        }
        else if (dir == Direction::RIGHT) {
            if (mX + mSpeed + mWidth / 2 <= 4) {
                mX += mSpeed;
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
        if (mFriendly)
            return move(Direction::RIGHT);
        else
            return move(Direction::LEFT);
    }

    bool Bullet::isFriendly() {
        return mFriendly;
    }

} // namespace model

