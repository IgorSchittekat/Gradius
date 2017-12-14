#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H
#pragma once

#include "../View/EntityObserver.h"
#include "../Utils/Vec2.h"

namespace view {
    class EntityObserver;
}

namespace model {
    enum class Notification {NONE, CREATED, MOVED, DELETED, HIT};

    class Entity {
    public:
        virtual ~Entity();

        Entity(util::Vec2d position, double width, double height, double speed);

        virtual Notification move(util::Vec2d dir) = 0;

        util::Vec2d getLocation() const;

        std::pair<double, double> getSize() const;

        void addEntityObserver(const std::shared_ptr<view::EntityObserver>& observer);

        virtual Notification update() = 0;

        void notify(Notification what);

        virtual bool canFire() { return false; }

    protected:
        util::Vec2d mPosition;
        double mWidth;
        double mHeight;
        double mSpeed;
    private:
        std::vector<std::shared_ptr<view::EntityObserver>> mObservers;

    };

} //namespace model

#endif //GRADIUS_ENTITY_H
