#include "Enemy.h"

namespace model {

    Enemy::Enemy(double x, double y, double speed, const std::string& type) :
            Entity(x, y, 0.8, 0.8, speed),
            mTimeUntilNextShot(18),
            mType(type) {
        mDir = Direction::UP;
    }

    Notification Enemy::update() {
        if (mType == "shooting") {
            mTimeUntilNextShot--;
            if (mY <= -2)
                mDir = Direction::DOWN;
            else if (mY >= 2)
                mDir = Direction::UP;
            return move(mDir);
        }
        else if (mType == "flying") {
            mDir = Direction::LEFT;
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