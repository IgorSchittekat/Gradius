#include <iostream>
#include "Entity.h"


namespace model {


    Entity::Entity() :
    mX(0),
    mY(0) {
    }

    Entity::Entity(double x, double y, double width, double height, double speed) :
    mX(x),
    mY(y),
    mWidth(width),
    mHeight(height),
    mSpeed(speed){
        notify(Notification::CREATED);
    }

    Entity::~Entity() {
        mObservers.clear();
    }

    Notification Entity::move(Direction dir) {
        switch (dir) {
            case Direction::UP:
                if (mY - mSpeed - mHeight >= -3)
                    mY -= mSpeed;
                break;
            case Direction::DOWN:
                if (mY + mSpeed + mHeight / 2 <= 3)
                    mY += mSpeed;
                break;
            case Direction::LEFT:
                if (mX - mSpeed - mWidth / 2 >= -4)
                    mX -= mSpeed;
                break;
            case Direction::RIGHT:
                if (mX + mSpeed + mWidth / 2 <= 4)
                    mX += mSpeed;
                break;
        }
        notify(Notification::MOVED);
        return Notification::MOVED;
    }

    std::pair<double, double> Entity::getLocation() const {
        return {mX, mY};
    }

    std::pair<double, double> Entity::getSize() const {
        return {mWidth, mHeight};
    }

    void Entity::addEntityObserver(const std::shared_ptr<view::EntityObserver>& observer) {
        mObservers.push_back(observer);
        observer->update(this, Notification::CREATED);
    }

    void Entity::notify(Notification what) {
        for (const std::shared_ptr<view::EntityObserver> &observer : mObservers) {
            observer->update(this, what);
        }
    }

}