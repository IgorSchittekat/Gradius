#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H
#pragma once

#include "../View/EntityObserver.h"
#include "../Utils/Vec2.h"
#include <memory>

namespace view {
    class EntityObserver;
}

namespace model {
    /**
     * @enum Notification of what can happen
     */
    enum class Notification {NONE, CREATED, MOVED, DELETED, HIT};

    class Entity {
    public:
        /**
         * @brief Constructor
         * @param position : Position of the Entity
         * @param width : Width of the Entity
         * @param height : Height of the Entity
         * @param speed : Speed of the Entity
         */
        Entity(util::Vec2d position, double width, double height, double speed);

        /**
         * @brief Destructor
         */
        virtual ~Entity();

        /**
         * @brief Move the entity
         * @param dir : Direction to move Entity in
         * @return Notification of what happened
         */
        virtual Notification move(util::Vec2d dir) = 0;

        /**
         * @brief Returns the location
         * @return Location of the Entity
         */
        util::Vec2d getLocation() const;

        /**
         * @brief Returns the size
         * @return Size of the Entity
         */
        std::pair<double, double> getSize() const;

        /**
         * @brief Adds an Observer to the list of observers
         * @param observer : Observer to be added
         */
        void addEntityObserver(const std::shared_ptr<view::EntityObserver>& observer);

        /**
         * @brief update the Entity
         * @return Notification of what happened
         */
        virtual Notification update() = 0;

        /**
         * @brief Update all Observers with Notification
         * @param what : Notification to update Observers
         */
        void notify(Notification what);

        /**
         * @brief Returns if the Entity can fire
         * @return bool if Entity can fire
         */
        virtual bool canFire() { return false; }

    protected:
        /**
         * @brief Position
         */
        util::Vec2d mPosition;
        /**
         * @brief Width
         */
        double mWidth;
        /**
         * @brief Height
         */
        double mHeight;
        /**
         * @brief Speed
         */
        double mSpeed;

    private:
        /**
         * @brief list of all Obserers
         */
        std::vector<std::shared_ptr<view::EntityObserver>> mObservers;
    };

} //namespace model

#endif //GRADIUS_ENTITY_H
