#include "Level.h"


namespace model {

    Level::Level() {

    }

    Level::Level(const Level &rhs) {

    }

    Level &Level::operator=(const Level &rhs) {
        return *this;
    }

    Level::~Level() {

    }

    void Level::update() {
        for (Entity* entity : m_entities) {
            entity->update(this);
        }
    }

    void Level::addEntity(Entity* entity) {
        m_entities.push_back(entity);
    }

    void Level::setShip(Ship *ship) {
        m_ship = ship;
    }

    Ship* Level::getShip() {
        return m_ship;
    }


} // namespace model
