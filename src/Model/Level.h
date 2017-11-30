#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H
#pragma once

#include <vector>
#include "Entity.h"

namespace view {
    class EntityObserver;
}

namespace model {

    class Ship;
    class Entity;

    class Level : public std::enable_shared_from_this<Level> {
    public:
        Level();

        Level(const Level &rhs);

        Level &operator=(const Level &rhs);

        ~Level();

        void update();

        void addEntity(std::shared_ptr<Entity>& entity);

        void setShip(std::shared_ptr<Ship> ship);

        std::shared_ptr<Ship> getShip() const;

        void setBulletSpeed(double speed);

        double getBulletSpeed() const;

    private:
        std::vector<std::shared_ptr<Entity>> m_entities;
        std::shared_ptr<Ship> m_ship;
        double m_bulletSpeed;
    };

} // namespace model


#endif //GRADIUS_LEVEL_H
