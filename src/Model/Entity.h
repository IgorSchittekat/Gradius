#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H
#pragma once

#include "../View/EntityObserver.h"
#include "Level.h"

namespace view {
    class EntityObserver;
    enum class Notification;
}

namespace model {

    enum Direction {UP, DOWN, LEFT, RIGHT};

    class Level;

    class Entity {
    public:
        Entity();

        Entity(double x, double y, double width, double height, double speed);

        virtual void move(Direction dir);

        std::pair<double, double> getLocation() const;

        std::pair<double, double> getSize() const;

        void addEntityObserver(view::EntityObserver* observer);

        virtual void update(const Level* lvl) {}

        void notify(view::Notification what) const;

    protected:
        double m_x;
        double m_y;
        double m_width;
        double m_height;
        double m_speed;
    private:
        std::vector<view::EntityObserver*> m_observers;

    };

} //namespace model

#endif //GRADIUS_ENTITY_H
