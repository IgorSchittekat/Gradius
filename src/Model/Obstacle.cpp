#include "Obstacle.h"

namespace model {

    Obstacle::Obstacle(util::Vec2d position, double speed, bool border) :
            Entity(position, 0.5, 0.5, speed),
            mBorder(border) {
    }

    Notification Obstacle::move(util::Vec2d dir) {
        mPosition += dir * mSpeed;
        if (mBorder) {
            if (mPosition.getX() < -4.5)
                mPosition = util::Vec2d(4.3, mPosition.getY());
        }
        else {
            if (mPosition.getX() < -4.5) {
                notify(Notification::DELETED);
                return Notification::DELETED;
            }
        }
        notify(Notification::MOVED);
        return Notification::MOVED;
    }

    Notification Obstacle::update() {
        return move(util::Vec2d(-1, 0));
    }

} // namespace model
