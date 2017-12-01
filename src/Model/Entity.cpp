#include <iostream>
#include "Entity.h"


namespace model {


    Entity::Entity() :
    m_x(0),
    m_y(0) {
    }

    Entity::Entity(double x, double y, double width, double height, double speed) :
    m_x(x),
    m_y(y),
    m_width(width),
    m_height(height),
    m_speed(speed){
        notify(Notification::CREATED);
    }

    Entity::~Entity() {
        m_observers.clear();
    }

    void Entity::move(Direction dir) {
        switch (dir) {
            case UP:
                if (m_y - m_speed - m_height >= -3)
                    m_y -= m_speed;
                break;
            case DOWN:
                if (m_y + m_speed + m_height / 2 <= 3)
                    m_y += m_speed;
                break;
            case LEFT:
                if (m_x - m_speed - m_width / 2 >= -4)
                    m_x -= m_speed;
                break;
            case RIGHT:
                if (m_x + m_speed + m_width / 2 <= 4)
                    m_x += m_speed;
                break;
            default:
                break;
        }
        notify(Notification::MOVED);
    }

    std::pair<double, double> Entity::getLocation() const {
        return {m_x, m_y};
    }

    std::pair<double, double> Entity::getSize() const {
        return {m_width, m_height};
    }

    void Entity::addEntityObserver(const std::shared_ptr<view::EntityObserver>& observer) {
        m_observers.push_back(observer);
        observer->update(this, Notification::CREATED);
    }

    void Entity::notify(Notification what) {
        for (const std::shared_ptr<view::EntityObserver> &observer : m_observers) {
            observer->update(this, what);
        }
    }

}