#include "Game.h"
#include "../Utils/Singleton.h"
#include "../Utils/Stopwatch.h"
#include <fstream>
#include <iostream>
#include "../Model/Ship.h"
#include "../Utils/Transformation.h"
#include "../Model/Entity.h"
#include "../Model/Enemy.h"

using json = nlohmann::json;

namespace ctrl {

    Game::Game() :
            m_lvl(1) {
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
        loadNextLevel();
    }

    void Game::loadNextLevel() {
        json data;
        std::ifstream JSON("../bin/resources/Game.json");
        if (JSON.is_open()) {
            JSON >> data;
            JSON.close();
        }
        else {
            return; //TODO: Exception
        }
        lvl = std::make_unique<model::Level>(model::Level());
        lvl->addObserver(wnd);
        wnd->loadTextures(data["level " + std::to_string(m_lvl)]["textures"]);
        lvl->setUp(data["level " + std::to_string(m_lvl)]);

        m_lvl++;
    }

    void Game::loadWindow(json data) {
        unsigned int width = data["window"]["width"];
        unsigned int height = data["window"]["height"];
        util::Transformation::getInstance()->setSize(width, height);
        std::string title = data["window"]["title"];
        std::string background = data["window"]["background"];
        wnd.reset(new view::Window(width, height, title, background));
    }

    void Game::play() {

        while (wnd->isOpen()) {
            util::Stopwatch::getInstance()->restart();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                lvl->moveShip(model::Direction::UP);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                lvl->moveShip(model::Direction::DOWN);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                lvl->moveShip(model::Direction::LEFT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                lvl->moveShip(model::Direction::RIGHT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                lvl->fireShip();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                    // Paused
                }
            }

            lvl->update();
            wnd->drawWindow();

            if (lvl->gameOver()) {
                std::cout << "GAME OVER" << std::endl;
                break;
            }
            while (util::Stopwatch::getInstance()->elapsed() < std::chrono::microseconds(16666)) {
                // Wait time to run at 60 fps at all computers
            }
        }
    }




} // namespace ctrl
