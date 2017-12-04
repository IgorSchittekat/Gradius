#include <iostream>
#include <utility>
#include "Level.h"
#include "Bullet.h"
#include "PlayerBullet.h"
#include "Enemy.h"

using json = nlohmann::json;

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
        for (int i = 0; i < enemies.size(); i++) {
            double x = enemies[i]["x"];
            double y = enemies[i]["y"];
            double enemySpeed = enemies[i]["speed"];
            std::shared_ptr<model::Entity> enemy = std::make_shared<model::Enemy>(model::Enemy(x, y, enemySpeed));
            auto enemyObservers = notify(enemy, Notification::CREATED);
            for (const std::shared_ptr<view::EntityObserver>& enemyObserver : enemyObservers) {
                enemy->addEntityObserver(enemyObserver);
            }
            addEntity(enemy);
        }

        // setUp Bullet
        m_bulletSpeed = data["bullet"]["speed"];
    }

    void Level::fireShip() {
        if (m_ship->canFire()) {
            std::shared_ptr<model::Entity> bullet = std::make_shared<PlayerBullet>(PlayerBullet(m_ship, m_bulletSpeed));
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
                    std::shared_ptr<model::Entity> bullet = std::make_shared<model::Bullet>(model::Bullet(*it, m_bulletSpeed));
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
    }


    std::vector<std::shared_ptr<Entity>> Level::getFiringEntities() {
        std::vector<std::shared_ptr<Entity>> firingEntities;
        for (const std::shared_ptr<Entity>& entity : m_entities) {
            if (entity->canFire())
                firingEntities.push_back(entity);
        }
        return firingEntities;
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


    bool Level::isColliding(const std::shared_ptr<Entity> &entity) {

    }

    void Level::addObserver(const std::shared_ptr<view::Window>& observer) {
        m_observers.push_back(observer);
    }

    void Level::moveShip(Direction dir) {
        m_ship->move(dir);
    }




} // namespace model
