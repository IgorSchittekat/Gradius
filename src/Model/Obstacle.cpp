#include "Obstacle.h"

namespace model {


    Obstacle::Obstacle(double x, double y, double speed, bool border) :
            Entity(x, y, 0.5, 0.5, speed),
            m_border(border) {

    }

    Notification Obstacle::move(Direction dir) {
        m_x -= m_speed;
        if (m_x < -4.5)
            m_x = 4.3;
        notify(Notification::MOVED);
        return Notification::MOVED;
    }

    Notification Obstacle::update() {
        return move(Direction::LEFT);
    }

}
