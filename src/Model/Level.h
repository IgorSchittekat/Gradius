#ifndef GRADIUS_LEVEL_H
#define GRADIUS_LEVEL_H
#pragma once

#include <vector>
#include "Entity.h"
//#include "Ship.h"

namespace view {
    class EntityObserver;
}

namespace model {

    class Ship;
    class Entity;

    class Level {
    public:
        Level();

        Level(const Level &rhs);

        Level &operator=(const Level &rhs);

        ~Level();

        void update();

        void addEntity(model::Entity* entity);

        void setShip(Ship* ship);

        Ship* getShip();

    private:
        std::vector<Entity*> m_entities;
        Ship* m_ship;
    };

} // namespace model


#endif //GRADIUS_LEVEL_H
