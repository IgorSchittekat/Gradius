#include <iostream>
#include "Entity.h"


namespace model {

    Entity::Entity(util::Vec2d position, double width, double height, double speed) :
            mPosition(position),
            mWidth(width),
            mHeight(height),
            mSpeed(speed){
        notify(Notification::CREATED);
    }

    Entity::~Entity() {
        mObservers.clear();
    }

    util::Vec2d Entity::getLocation() const {
        return mPosition;
    }

    std::pair<double, double> Entity::getSize() const {
        return {mWidth, mHeight};
    }

    void Entity::addEntityObserver(const std::shared_ptr<view::EntityObserver>& observer) {
        mObservers.push_back(observer);
    }

    void Entity::notify(Notification what) {
        for (const std::shared_ptr<view::EntityObserver> &observer : mObservers) {
            observer->update(this, what);
        }
    }

}