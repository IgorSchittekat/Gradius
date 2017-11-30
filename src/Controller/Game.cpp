#include "Game.h"
#include "Singleton.h"
#include "Stopwatch.h"
#include <fstream>
#include <iostream>
#include "../Model/Ship.h"
#include "Transformation.h"
#include "../Model/Entity.h"
#include "../Model/Bullet.h"

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
        loadShip(data);
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
        std::string type = data["level 1"]["ship"]["type"];
        lvl = std::make_unique<model::Level>(model::Level());
        auto ship = std::make_shared<model::Ship>(model::Ship(lives, speed));
        auto shipObserver = std::make_shared<view::EntityObserver>(view::EntityObserver(wnd, shipTexture, type));
        ship->addEntityObserver(shipObserver);
        wnd->addEntityObserver(shipObserver);
        lvl->setShip(ship);
    }

    void Game::loadEnemy(json data) {
        std::string enemyTexture = data["level 1"]["enemy"]["texture"];
    }

    void Game::loadBulletTexture(json data) {
        std::string playerBulletTexture = data["level 1"]["bullet"]["playerBullet"]["texture"];
        std::string playerBulletType = data["level 1"]["bullet"]["playerBullet"]["type"];
        std::string enemyBulletTexture = data["level 1"]["bullet"]["enemyBullet"]["texture"];
        std::string enemyBulletType = data["level 1"]["bullet"]["enemyBullet"]["type"];
        double speed = data["level 1"]["bullet"]["speed"];
        wnd->addTexture(playerBulletType, playerBulletTexture);
        wnd->addTexture(enemyBulletType, enemyBulletTexture);
        lvl->setBulletSpeed(speed);
    }


    void Game::play() {

        ctrl::Stopwatch* stopwatch = ctrl::Singleton<ctrl::Stopwatch>::getInstance();


        while (wnd->isOpen()) {
            stopwatch->restart();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                lvl->getShip()->move(model::UP);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                lvl->getShip()->move(model::DOWN);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                lvl->getShip()->move(model::LEFT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                lvl->getShip()->move(model::RIGHT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                if (lvl->getShip()->canFire()) {
                    std::shared_ptr<model::Entity> bullet = std::make_shared<model::Bullet>(model::Bullet(lvl->getShip(), lvl->getBulletSpeed()));
                    auto bulletObserver = std::make_shared<view::EntityObserver>(view::EntityObserver(wnd, "playerBullet"));
                    bullet->addEntityObserver(bulletObserver);
                    wnd->addEntityObserver(bulletObserver);
                    lvl->addEntity(bullet);
                }
            }
            lvl->getShip()->updateShots();


            lvl->update();
            wnd->drawWindow();

            while (stopwatch->elapsed() < std::chrono::microseconds(16666)) {
                // Wait time to run at 60 fps at all computers
            }

        }
    }




} // namespace ctrl
