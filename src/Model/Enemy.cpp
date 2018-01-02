#include <iostream>
#include "Enemy.h"
#include "../Utils/Vec2.h"

namespace model {

    Enemy::Enemy(util::Vec2d position, double speed, std::string type) :
            Entity(position, 0.8, 0.4, speed),
            mDir(util::Vec2d(-0.5, 1)),
            mTimeUntilNextShot(18),
            mType(std::move(type)){
    }

    Notification Enemy::move(util::Vec2d dir) {
        mPosition += dir * util::Vec2d(0.085, mSpeed);
        if (mPosition.getX() < -4.5) {
            mPosition = util::Vec2d(4.5, mPosition.getY());
        }
        notify(Notification::MOVED);
        return Notification::MOVED;
    }

    Notification Enemy::update() {
        if (mType == "shooting") {
            mTimeUntilNextShot--;
            mDir = util::Vec2d(-mSpeed, 0);
            return move(mDir);
        }
        else if (mType == "flying") {
            if (mPosition.getY() <= -2) {
                mDir = util::Vec2d(-0.5, 1);
            }
            else if (mPosition.getY() >= 2) {
                mDir = util::Vec2d(-0.5, -1);
            }
            return move(mDir);
        }
        return Notification::NONE;
    }

    bool Enemy::canFire() {
        if (mTimeUntilNextShot <= 0 && mPosition.getX() < 4) {
            mTimeUntilNextShot = 150;
            return true;
        }
        return false;
    }

    std::string Enemy::getType() const {
        return mType;
    }

} // namespace model