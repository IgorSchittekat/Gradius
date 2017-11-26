#include <iostream>
#include "Entity.h"


namespace model {


    Entity::Entity() :
    m_x(0),
    m_y(0) {
    }

    Entity::Entity(double x, double y, double speed) :
    m_x(x),
    m_y(y),
    m_speed(speed){
    }

    void Entity::move(Direction dir) {
        switch (dir) {
            case UP:
                m_y -= m_speed;
                break;
            case DOWN:
                m_y += m_speed;
                break;
            case LEFT:
                m_x -= m_speed;
                break;
            case RIGHT:
                m_x += m_speed;
                break;
            default:
                break;
        }
    }

    double Entity::getX() const {
        return m_x;
    }

    double Entity::getY() const {
        return m_y;
    }


}