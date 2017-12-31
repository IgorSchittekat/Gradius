#include "Game.h"
#include "../Utils/Singleton.h"
#include "../Utils/Stopwatch.h"
#include <fstream>
#include <iostream>
#include "../Model/Ship.h"
#include "../Utils/Transformation.h"
#include "../Model/Entity.h"
#include "../Model/Enemy.h"
#include "../Utils/Vec2.h"
#include "../Utils/GradiusException.h"

namespace ctrl {

    Game::Game() :
            mCurrentLvl(0) {
        nlohmann::json data;
        std::ifstream JSON("../bin/resources/Game.json");
        if (JSON.is_open()) {
            JSON >> data;
            JSON.close();
        }
        else {
            throw util::GradiusException("Unable to open file: bin/resources/Game.json");
        }
        loadWindow(data["window"]);
        loadNextLevel();
    }

    bool Game::loadNextLevel() {
        if (mTotalLvls == mCurrentLvl) {
            return false;
        }
        nlohmann::json data;
        std::ifstream JSON("../bin/resources/Game.json");
        if (JSON.is_open()) {
            JSON >> data;
            JSON.close();
        }
        else {
            throw util::GradiusException("Unable to open file: bin/resources/Game.json");
        }
        mLvl = std::make_unique<model::Level>(model::Level());
        mLvl->addObserver(mWnd);
        mWnd->loadTextures(data["level " + std::to_string(mCurrentLvl)]["textures"]);
        mLvl->setUp(data["level " + std::to_string(mCurrentLvl)]);

        mCurrentLvl++;
        return true;
    }

    void Game::loadWindow(nlohmann::json data) {
        unsigned int width = data["width"];
        unsigned int height = data["height"];
        util::Transformation::getInstance()->setSize(width, height);
        std::string title = data["title"];
        mWnd.reset(new view::Window(width, height, title, data["background"]));
        mWnd->addTexture("victory", data["victory"]);
        mWnd->addTexture("gameOver", data["gameOver"]);
        mTotalLvls = data["totalLevels"];
    }

    void Game::play() {

        while (mWnd->isOpen()) {
            util::Stopwatch::getInstance()->restart();
            double x = 0;
            double y = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                y--;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                y++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                x--;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                x++;
            }
            mLvl->moveShip(util::Vec2d(x, y).normalise());

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                mLvl->fireShip();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                    // Paused
                }
            }

            mLvl->update();
            mWnd->drawWindow();

            model::Levelstatus status = mLvl->getStatus();
            if (status == model::Levelstatus::GAMEOVER) {
                mWnd->drawGameOver();
                break;
            }
            else if (status == model::Levelstatus::VICTORY) {
                mWnd->drawVictory();
                if (!loadNextLevel()) {
                    break;
                }
            }
            while (util::Stopwatch::getInstance()->elapsed() < std::chrono::microseconds(16666)) {
                // Wait time to run at 60 fps at all computers
            }
        }
    }




} // namespace ctrl
