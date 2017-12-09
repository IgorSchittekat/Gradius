#include <iostream>
#include <utility>
#include "Level.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Obstacle.h"

using json = nlohmann::json;

namespace model {

    auto Level::notify(const std::shared_ptr<Entity>& entity, Notification what) {
        std::vector<std::shared_ptr<view::EntityObserver>> entityObservers;
        for (const auto& observer : m_observers) {
            entityObservers.push_back(observer->update(entity, what));
        }
        return entityObservers;
    }

    void Level::setUp(json data) {
        // setUp Ship
        unsigned int lives = data["ship"]["lives"];
        double shipSpeed = data["ship"]["speed"];
        auto ship = std::make_shared<Ship>(Ship(lives, shipSpeed));
        auto shipObservers = notify(ship, Notification::CREATED);
        for (const std::shared_ptr<view::EntityObserver>& shipObserver : shipObservers) {
            ship->addEntityObserver(shipObserver);
        }
        setShip(ship);

        // setUp Enemies
        auto enemies = data["enemy"];
        for (auto& enemy : enemies) {
            double x = enemy["x"];
            double y = enemy["y"];
            double enemySpeed = enemy["speed"];
            std::string type = enemy["type"];
            std::shared_ptr<model::Entity> newEnemy = std::make_shared<model::Enemy>(model::Enemy(x, y, enemySpeed, type));
            auto enemyObservers = notify(newEnemy, Notification::CREATED);
            for (const std::shared_ptr<view::EntityObserver>& enemyObserver : enemyObservers) {
                newEnemy->addEntityObserver(enemyObserver);
            }
            addEntity(newEnemy);
        }

        // setUp Bullet
        m_bulletSpeed = data["bullet"]["speed"];
    }

    void Level::fireShip() {
        if (m_ship->canFire()) {
            std::shared_ptr<model::Entity> bullet = std::make_shared<Bullet>(Bullet(m_ship, m_bulletSpeed, true));
            auto bulletObservers = notify(bullet, Notification::CREATED);
            for (const std::shared_ptr<view::EntityObserver>& bulletObserver : bulletObservers) {
                bullet->addEntityObserver(bulletObserver);
            }
            addEntity(bullet);
        }
    }

    void Level::update() {
        m_ship->update();
        std::vector<std::shared_ptr<Entity>> newEntities;
        for (auto it = m_entities.begin(); it != m_entities.end(); ) {

            Notification n = (*it)->update();
            if (n == Notification::DELETED) {
                it = m_entities.erase(it);
            }
            else {
                if ((*it)->canFire()) {
                    std::shared_ptr<model::Entity> bullet = std::make_shared<model::Bullet>(model::Bullet(*it, m_bulletSpeed, false));
                    auto bulletObservers = notify(bullet, Notification::CREATED);
                    for (const std::shared_ptr<view::EntityObserver>& bulletObserver : bulletObservers) {
                        bullet->addEntityObserver(bulletObserver);
                    }
                    newEntities.push_back(bullet);
                }
                ++it;
            }
        }
        for (auto& newEntity : newEntities) {
            addEntity(newEntity);
        }
        removeCollidingEntities();
    }

    void Level::removeCollidingEntities() {
        auto collidingWithShip = isColliding(m_ship);
        for (std::shared_ptr<Entity>& entity : collidingWithShip) {
            if (std::shared_ptr<Bullet> bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
                if (!bullet->isFriendly()) {
                    m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), entity), m_entities.end());
                    m_ship->hit(1);
                }
            }
            else if (std::dynamic_pointer_cast<Enemy>(entity)) {
                m_ship->hit(1);
            }
            else if (std::dynamic_pointer_cast<Obstacle>(entity)) {
                m_ship->hit(1);
            }
            else if (std::dynamic_pointer_cast<Enemy>(entity)) {
                m_ship->hit(1);
            }
        }
    }

    void Level::addEntity(std::shared_ptr<Entity>& entity) {
        m_entities.push_back(std::move(entity));
    }

    void Level::setShip(std::shared_ptr<Ship> ship) {
        m_ship = std::move(ship);
    }

    std::vector<std::shared_ptr<Entity>> Level::isColliding(const std::shared_ptr<Entity>& entity) {
        std::vector<std::shared_ptr<Entity>> collidingEntities;
        for (const auto& otherEntity : m_entities) {
            if (entity != otherEntity) {
                std::pair<double, double> entitySize = entity->getSize();
                std::pair<double, double> entityPosition = {entity->getLocation().first - entitySize.first / 2,
                                                            entity->getLocation().second - entitySize.second / 2};
                std::pair<double, double> otherEntitySize = otherEntity->getSize();
                std::pair<double, double> otherEntityPosition = {otherEntity->getLocation().first - otherEntitySize.first / 2,
                                                                 otherEntity->getLocation().second - otherEntitySize.second / 2};

                if(entityPosition.first < otherEntityPosition.first + otherEntitySize.first &&
                        otherEntityPosition.first < entityPosition.first + entitySize.first &&
                        entityPosition.second < otherEntityPosition.second + otherEntitySize.second &&
                        otherEntityPosition.second < entityPosition.second + entitySize.second) {
                    collidingEntities.push_back(otherEntity);
                }
            }
        }
        return collidingEntities;
    }

    void Level::addObserver(const std::shared_ptr<view::Window>& observer) {
        m_observers.push_back(observer);
    }

    void Level::moveShip(Direction dir) {
        m_ship->move(dir);
    }




} // namespace model
