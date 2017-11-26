#include "Game.h"
#include "json.hpp"
#include "Singleton.h"
#include "Stopwatch.h"
#include <fstream>
#include "../Model/Ship.h"
#include "Transformation.h"

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
        unsigned int width = data["window"]["width"];
        unsigned int height = data["window"]["height"];
        std::string title = data["window"]["title"];
        std::string background = data["window"]["background"];
        wnd = new view::Window(width, height, title, background);
        Singleton<Transformation>::getInstance()->setSize(width, height);
        unsigned int lives = data["level 1"]["ship"]["lives"];
        std::string shipTexture = data["level 1"]["ship"]["texture"];
        double speed = data["level 1"]["ship"]["speed"];
        lvl = new model::Level();
        auto ship = new model::Ship(lives, speed);
        auto shipObserver = new view::EntityObserver(shipTexture);
        ship->addEntityObserver(shipObserver);
        wnd->addEntityObserver(shipObserver);
        lvl->setShip(ship);
    }


    void Game::play() {

        ctrl::Stopwatch* stopwatch = ctrl::Singleton<ctrl::Stopwatch>::getInstance();


        while (wnd->isOpen()) {
            stopwatch->restart();
            sf::Event event {};
            while (wnd->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    wnd->close();
            }

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

            lvl->update();
            wnd->drawWindow();

            while (stopwatch->elapsed() < std::chrono::microseconds(16666)) {
                // Wait time to run at 60 fps at all computers
            }

        }
    }


} // namespace ctrl
