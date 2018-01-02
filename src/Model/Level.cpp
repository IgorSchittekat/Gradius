#include <iostream>
#include "Level.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Obstacle.h"

namespace model {

    void Level::notify(const std::shared_ptr<Entity>& entity, Notification what) {
        for (const auto& observer : mObservers) {
            observer->update(entity, what);
        }
    }

    void Level::setUp(nlohmann::json data) {
        // setUp Ship
        unsigned int lives = data["ship"]["lives"];
        double shipSpeed = data["ship"]["speed"];
        auto ship = std::make_shared<Ship>(Ship(lives, shipSpeed));
        notify(ship, Notification::CREATED);
        setShip(ship);

        // setUp Enemies
        auto enemies = data["enemy"];
        for (auto& enemy : enemies) {
            double x = enemy["x"];
            double y = enemy["y"];
            double enemySpeed = enemy["speed"];
            std::string type = enemy["type"];
            std::shared_ptr<Entity> newEnemy = std::make_shared<Enemy>(Enemy(util::Vec2d(x, y), enemySpeed, type));
            notify(newEnemy, Notification::CREATED);
            addEntity(newEnemy);
        }

        // setUp Bullet
        mBulletSpeed = data["bullet"]["speed"];

        // setUp Walls
        for (int i = 0; i < 22; i++) {
            std::shared_ptr<Entity> obstacle = std::make_shared<Obstacle>(Obstacle(util::Vec2d(-3.8 + 0.4 * i, -2.8), 0.045, true));
            notify(obstacle, Notification::CREATED);
            addEntity(obstacle);
            std::shared_ptr<Entity> obstacle2 = std::make_shared<Obstacle>(Obstacle(util::Vec2d(-3.8 + 0.4 * i, 2.8), 0.045, true));
            notify(obstacle2, Notification::CREATED);
            addEntity(obstacle2);
        }

        //setUp Obstacles
        auto obstacles = data["obstacle"];
        for (auto& newObstacle : obstacles) {
            double x = newObstacle["x"];
            double y = newObstacle["y"];
            std::shared_ptr<Entity> obstacle = std::make_shared<Obstacle>(Obstacle(util::Vec2d(x, y), 0.045, false));
            notify(obstacle, Notification::CREATED);
            addEntity(obstacle);
        }
    }

    void Level::fireShip() {
        if (mShip->canFire()) {
            std::shared_ptr<model::Entity> bullet = std::make_shared<Bullet>(Bullet(mShip, mBulletSpeed, true));
            notify(bullet, Notification::CREATED);
            addEntity(bullet);
        }
    }

    void Level::update() {
        // update ship
        mShip->update();
        // update other entities
        std::vector<std::shared_ptr<Entity>> newEntities;
        for (auto it = mEntities.begin(); it != mEntities.end(); ) {

            Notification n = (*it)->update();
            notify(*it, n);
            if (n == Notification::DELETED) {
                it = mEntities.erase(it);
            }
            else {
                if ((*it)->canFire()) {
                    std::shared_ptr<Entity> bullet = std::make_shared<Bullet>(Bullet(*it, mBulletSpeed, false));
                    notify(bullet, Notification::CREATED);
                    newEntities.push_back(bullet);
                }
                ++it;
            }
        }
        // add new Bullets
        for (auto& newEntity : newEntities) {
            addEntity(newEntity);
        }
        // Remove Colliding Entities
        removeCollidingEntities();
    }

    void Level::removeCollidingEntities() {
        auto collidingWithShip = getColliding(mShip);
        for (std::shared_ptr<Entity>& entity : collidingWithShip) {
            if (std::shared_ptr<Bullet> bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
                if (!bullet->isFriendly()) {
                    mEntities.erase(std::remove(mEntities.begin(), mEntities.end(), entity), mEntities.end());
                    if (mShip->hit(1))
                        notify(mShip, Notification::HIT);
                }
            }
            if (std::dynamic_pointer_cast<Enemy>(entity)) {
                if (mShip->hit(1))
                    notify(mShip, Notification::HIT);
            }
            if (std::shared_ptr<Obstacle> obstacle = std::dynamic_pointer_cast<Obstacle>(entity)) {
                if (obstacle->isBorder()) {
                    if (mShip->hit(2)) {
                        notify(mShip, Notification::HIT);
                    }
                }
                else {
                    if (mShip->hit(1)) {
                        notify(mShip, Notification::HIT);
                    }
                }
            }
        }
        std::vector<std::shared_ptr<Entity>> toRemove;
        for (const auto& entity : mEntities) {
            if (std::dynamic_pointer_cast<Obstacle>(entity)) {
                continue;
            }
            auto collidingWithEntity = getColliding(entity);
            for (std::shared_ptr<Entity>& otherEntity : collidingWithEntity) {
                if (std::shared_ptr<Bullet> bullet = std::dynamic_pointer_cast<Bullet>(entity)) {
                    if (std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(otherEntity)) {
                        if (bullet->isFriendly()) {
                            toRemove.push_back(entity);
                            toRemove.push_back(otherEntity);
                        }
                    }
                }
            }
        }
        for (const auto& entity : toRemove) {
            mEntities.erase(std::remove(mEntities.begin(), mEntities.end(), entity), mEntities.end());
        }
    }

    std::vector<std::shared_ptr<Entity>> Level::getColliding(const std::shared_ptr<Entity>& entity) {
        std::vector<std::shared_ptr<Entity>> collidingEntities;
        for (const auto& otherEntity : mEntities) {
            if (entity != otherEntity) {
                std::pair<double, double> entitySize = entity->getSize();
                std::pair<double, double> entityPosition = {entity->getLocation().getX() - entitySize.first / 2,
                                                            entity->getLocation().getY() - entitySize.second / 2};
                std::pair<double, double> otherEntitySize = otherEntity->getSize();
                std::pair<double, double> otherEntityPosition = {otherEntity->getLocation().getX() - otherEntitySize.first / 2,
                                                                 otherEntity->getLocation().getY() - otherEntitySize.second / 2};

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

    void Level::addEntity(std::shared_ptr<Entity>& entity) {
        mEntities.push_back(std::move(entity));
    }

    void Level::setShip(std::shared_ptr<Ship> ship) {
        mShip = std::move(ship);
    }

    void Level::addObserver(const std::shared_ptr<view::Window>& observer) {
        mObservers.push_back(observer);
    }

    void Level::moveShip(util::Vec2d dir) {
        mShip->move(dir);
    }

    Levelstatus Level::getStatus() {
        if (!mShip->isAlive()) {
            return Levelstatus::GAMEOVER;
        }
        for (const std::shared_ptr<Entity>& entity : mEntities) {
            if (std::shared_ptr<Obstacle> obstacle = std::dynamic_pointer_cast<Obstacle>(entity)) {
                if (!obstacle->isBorder()) {
                    return Levelstatus::PLAYING;
                }
            }
            if (std::dynamic_pointer_cast<Enemy>(entity)) {
                return Levelstatus::PLAYING;
            }

        }
        return Levelstatus::VICTORY;
    }

} // namespace model
