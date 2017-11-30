#include <iostream>
#include <utility>
#include "Level.h"
#include "Bullet.h"


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
        for (const std::shared_ptr<Entity>& entity : m_entities) {
//            entity->update(shared_from_this());
        }
    }

    void Level::addEntity(std::shared_ptr<Entity>& entity) {
        m_entities.push_back(entity);
    }

    void Level::setShip(std::shared_ptr<Ship> ship) {
        m_ship = std::move(ship);
    }

    std::shared_ptr<Ship> Level::getShip() const {
        return m_ship;
    }

    void Level::setBulletSpeed(double speed) {
        m_bulletSpeed = speed;
    }

    double Level::getBulletSpeed() const {
        return m_bulletSpeed;
    }



} // namespace model
