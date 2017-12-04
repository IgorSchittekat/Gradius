#include "Game.h"
#include "Singleton.h"
#include "Stopwatch.h"
#include <fstream>
#include <iostream>
#include "../Model/Ship.h"
#include "Transformation.h"
#include "../Model/Entity.h"
#include "../Model/PlayerBullet.h"
#include "../Model/Enemy.h"

using json = nlohmann::json;

namespace ctrl {

    Game::Game() {
        json data;
        std::ifstream JSON("../bin/resources/Game.json");
        if (JSON.is_open()) {
            JSON >> data;
            JSON.close();
        }
        else {
            return; //TODO: Exception
        }
        loadWindow(data);
        lvl = std::make_unique<model::Level>(model::Level());


        loadShip(data);
        loadEnemy(data);
        loadBulletTexture(data);
    }

    void Game::loadWindow(json data) {
        unsigned int width = data["window"]["width"];
        unsigned int height = data["window"]["height"];
        Singleton<Transformation>::getInstance()->setSize(width, height);
        std::string title = data["window"]["title"];
        std::string background = data["window"]["background"];
        wnd.reset(new view::Window(width, height, title, background));
        std::string heart = data["window"]["heart"];

    }

    void Game::loadShip(json data) {
        unsigned int lives = data["level 1"]["ship"]["lives"];
        std::string shipTexture = data["level 1"]["ship"]["texture"];
        double speed = data["level 1"]["ship"]["speed"];
        auto ship = std::make_shared<model::Ship>(model::Ship(lives, speed));
        auto shipObserver = std::make_shared<view::EntityObserver>(view::EntityObserver(wnd, shipTexture, "Ship"));
        ship->addEntityObserver(shipObserver);
        wnd->addEntityObserver(std::weak_ptr<view::EntityObserver>(shipObserver));
        lvl->setShip(ship);
    }

    void Game::loadEnemy(json data) {
        auto enemies = data["level 1"]["enemy"];
        for (int i = 0; i < enemies.size(); i++) {
            std::string enemyTexture = data["level 1"]["enemy"][i]["texture"];
            wnd->addTexture("Enemy", enemyTexture);
            double x = enemies[i]["x"];
            double y = enemies[i]["y"];
            double speed = enemies[i]["speed"];
            std::shared_ptr<model::Entity> enemy = std::make_shared<model::Enemy>(model::Enemy(x, y, speed));
            auto enemyObserver = std::make_shared<view::EntityObserver>(view::EntityObserver(wnd, "Enemy"));
            enemy->addEntityObserver(enemyObserver);
            wnd->addEntityObserver(std::weak_ptr<view::EntityObserver>(enemyObserver));
            lvl->addEntity(enemy);
        }
    }

    void Game::loadBulletTexture(json data) {
        std::string playerBulletTexture = data["level 1"]["bullet"]["playerBulletTexture"];
        std::string enemyBulletTexture = data["level 1"]["bullet"]["enemyBulletTexture"];
        double speed = data["level 1"]["bullet"]["speed"];
        wnd->addTexture("PlayerBullet", playerBulletTexture);
        wnd->addTexture("EnemyBullet", enemyBulletTexture);
        lvl->setBulletSpeed(speed);
    }


    void Game::play() {

        ctrl::Stopwatch* stopwatch = ctrl::Singleton<ctrl::Stopwatch>::getInstance();


        while (wnd->isOpen()) {
            stopwatch->restart();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                lvl->getShip()->move(model::Direction::UP);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                lvl->getShip()->move(model::Direction::DOWN);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                lvl->getShip()->move(model::Direction::LEFT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                lvl->getShip()->move(model::Direction::RIGHT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                if (lvl->getShip()->canFire()) {
                    std::shared_ptr<model::Entity> bullet = std::make_shared<model::PlayerBullet>(model::PlayerBullet(lvl->getShip(), lvl->getBulletSpeed()));
                    auto bulletObserver = std::make_shared<view::EntityObserver>(view::EntityObserver(wnd, "PlayerBullet"));
                    bullet->addEntityObserver(bulletObserver);
                    wnd->addEntityObserver(std::weak_ptr<view::EntityObserver>(bulletObserver));
                    lvl->addEntity(bullet);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O));
            }



            lvl->getShip()->update();

            auto firingEntities = lvl->getFiringEntities();
            for (const std::shared_ptr<model::Entity>& entity : firingEntities) {
                std::shared_ptr<model::Entity> bullet = std::make_shared<model::Bullet>(model::Bullet(entity, lvl->getBulletSpeed()));
                auto bulletObserver = std::make_shared<view::EntityObserver>(view::EntityObserver(wnd, "EnemyBullet"));
                bullet->addEntityObserver(bulletObserver);
                wnd->addEntityObserver(std::weak_ptr<view::EntityObserver>(bulletObserver));
                lvl->addEntity(bullet);
            }

            lvl->update();
            wnd->deleteObservers();
            wnd->drawWindow();

            while (stopwatch->elapsed() < std::chrono::microseconds(16666)) {
                // Wait time to run at 60 fps at all computers
            }

        }
    }




} // namespace ctrl
