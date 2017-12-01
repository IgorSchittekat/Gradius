#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H
#pragma once

#include "../View/EntityObserver.h"
#include "Level.h"

namespace view {
    class EntityObserver;
}

namespace model {
    enum class Notification {CREATED, MOVED, DELETED};
    enum Direction {UP, DOWN, LEFT, RIGHT};

    class Level;

    class Entity {
    public:
        Entity();
        virtual ~Entity();

        Entity(double x, double y, double width, double height, double speed);

        virtual void move(Direction dir);

        std::pair<double, double> getLocation() const;

        std::pair<double, double> getSize() const;

        void addEntityObserver(const std::shared_ptr<view::EntityObserver>& observer);

        virtual Notification update() {}

        void notify(Notification what);

        virtual bool canFire() { return false; }

    protected:
        double m_x;
        double m_y;
        double m_width;
        double m_height;
        double m_speed;
    private:
        std::vector<std::shared_ptr<view::EntityObserver>> m_observers;

    };

} //namespace model

#endif //GRADIUS_ENTITY_H
