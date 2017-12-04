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
        for (auto it = m_entities.begin(); it != m_entities.end();) {
            Notification n = (*it)->update();
            if (n == Notification::DELETED) {
                it = m_entities.erase(it);
            }
            else {
                ++it;
            }
        }
//        for (const std::shared_ptr<Entity>& )
    }

    void Level::addEntity(std::shared_ptr<Entity>& entity) {
        m_entities.push_back(std::move(entity));
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

    std::vector<std::shared_ptr<Entity>> Level::getFiringEntities() {
        std::vector<std::shared_ptr<Entity>> firingEntities;
        for (const std::shared_ptr<Entity>& entity : m_entities) {
            if (entity->canFire())
                firingEntities.push_back(entity);
        }
        return firingEntities;
    }

    bool Level::isColliding(const std::shared_ptr<Entity> &entity) {

    }


} // namespace model
