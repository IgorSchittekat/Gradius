#include "Obstacle.h"

namespace model {


    Obstacle::Obstacle(double x, double y, double speed, bool border) :
            Entity(x, y, 0.5, 0.5, speed),
            mBorder(border) {

    }

    Notification Obstacle::move(Direction dir) {
        mX -= mSpeed;
        if (mX < -4.5)
            mX = 4.3;
        notify(Notification::MOVED);
        return Notification::MOVED;
    }

    Notification Obstacle::update() {
        return move(Direction::LEFT);
    }

}
