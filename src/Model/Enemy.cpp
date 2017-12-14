#include "Enemy.h"
#include "../Utils/Vec2.h"

namespace model {

    Enemy::Enemy(util::Vec2d position, double speed, std::string type) :
            Entity(position, 0.8, 0.4, speed),
            mTimeUntilNextShot(18),
            mType(std::move(type)),
            mDir(1, 0) {

    }

    Notification Enemy::move(util::Vec2d dir) {
        mPosition += dir * mSpeed;
        if (mPosition.getX() < -4.5) {
            notify(Notification::DELETED);
            return Notification::DELETED;
        }
        else {
            notify(Notification::MOVED);
            return Notification::MOVED;
        }
    }

    Notification Enemy::update() {
        if (mType == "shooting") {
            mTimeUntilNextShot--;
            if (mPosition.getY() <= -2)
                mDir = util::Vec2d(0, -1);
            else if (mPosition.getY() >= 2)
                mDir = util::Vec2d(0, 1);
            return move(mDir);
        }
        else if (mType == "flying") {
            mDir = util::Vec2d(-1, 0);
            return move(mDir);
        }
        return Notification::NONE;
    }

    bool Enemy::canFire() {
        if (mTimeUntilNextShot <= 0) {
            mTimeUntilNextShot = 80;
            return true;
        }
        return false;
    }

    std::string Enemy::getType() const {
        return mType;
    }


}