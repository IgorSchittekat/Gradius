#include "Window.h"
#include "../Model/Enemy.h"
#include "../Model/Ship.h"
#include "../Model/Bullet.h"
#include "../Model/Obstacle.h"
#include "../Utils/Stopwatch.h"
#include "../Utils/GradiusException.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

namespace view {
    
    Window::Window(unsigned int width, unsigned int height, const std::string &title, const std::string& background) {
        mWnd.reset(new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar));
        addTexture("background", background);
        mBackground.setTexture(*mTextures["background"]);
        mHearts = 0;
    }

    bool Window::isOpen() {
        sf::Event event {};
        while (mWnd->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                mWnd->close();
        }
        return mWnd->isOpen();
    }

    void Window::drawWindow() {
        mWnd->clear();
        drawBackground();
        drawHearts();
        for (const std::weak_ptr<EntityObserver>& entity : mEntities) {
            if (!entity.expired())
                entity.lock()->draw(*mWnd);
        }
        mWnd->display();
    }

    void Window::drawBackground() {
        mBackground.move(-0.8f, 0.0);
        mWnd->draw(mBackground);
        if (mBackground.getPosition().x < -(int)mBackground.getTexture()->getSize().x / 2) {
            mBackground.setPosition(-2, 0);

        }
    }

    void Window::drawHearts() {
        for ( int i = 0; i < mHearts; i++) {
            sf::Sprite heart;
            heart.setTexture(*mTextures["heart"]);
            heart.setPosition(0 + mWnd->getSize().x / 70 * i, mWnd->getSize().y / 12);
            mWnd->draw(heart);
        }
    }

    void Window::addEntityObserver(const std::weak_ptr<EntityObserver>& entityObserver) {
        mEntities.push_back(entityObserver);
    }

    void Window::addTexture(const std::string& name, const std::string& fileName) {
        sf::Image i;
        if (!i.loadFromFile(fileName)) {
            throw util::GradiusException("Unable to open file", __FILE__, __LINE__);
        }
        i.createMaskFromColor(i.getPixel(0, 0));
        auto texture = std::make_shared<sf::Texture>(sf::Texture());
        texture->loadFromImage(i);
        mTextures[name] = std::move(texture);
    }

    void Window::update(const std::shared_ptr<model::Entity>& entity, model::Notification what) {
        if (what == model::Notification::CREATED) {
            std::string type;
            if (std::shared_ptr<model::Enemy> enemy = std::dynamic_pointer_cast<model::Enemy>(entity))
                type = enemy->getType() + "Enemy";
            else if (std::shared_ptr<model::Ship> ship = std::dynamic_pointer_cast<model::Ship>(entity)) {
                type = "ship";
                mHearts = ship->getLives();
            }
            else if (std::dynamic_pointer_cast<model::Obstacle>(entity))
                type = "obstacle";
            else if (std::shared_ptr<model::Bullet> bullet = std::dynamic_pointer_cast<model::Bullet>(entity)) {
                if (bullet->isFriendly())
                    type = "playerBullet";
                else
                    type = "enemyBullet";
            }
            auto entityObserver = std::make_shared<view::EntityObserver>(view::EntityObserver(*mTextures[type]));
            addEntityObserver(entityObserver);
            entity->addEntityObserver(entityObserver);
            entityObserver->update(entity.get(), model::Notification::CREATED);
        }
        else if (what == model::Notification::DELETED) {
            for (auto it = mEntities.begin(); it != mEntities.end(); ){
                if (it->expired()) {
                    it = mEntities.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
        else if (what == model::Notification::HIT) {
            if (std::shared_ptr<model::Ship> ship = std::dynamic_pointer_cast<model::Ship>(entity)) {
                mHearts = ship->getLives();
            }
        }
    }

    void Window::loadTextures(nlohmann::json data) {
        addTexture("ship", data["ship"]);
        addTexture("shootingEnemy", data["shootingEnemy"]);
        addTexture("flyingEnemy", data["flyingEnemy"]);
        addTexture("playerBullet", data["playerBullet"]);
        addTexture("enemyBullet", data["enemyBullet"]);
        addTexture("obstacle", data["obstacle"]);
        addTexture("heart", data["heart"]);
    }

    void Window::drawVictory() {
        mWnd->clear();
        sf::Sprite victory;
        victory.setTexture(*mTextures["victory"]);
        victory.setPosition(mWnd->getSize().x / 2, mWnd->getSize().y / 2);
        victory.setOrigin(victory.getTextureRect().width / 2, victory.getTextureRect().height / 2);
        mWnd->draw(victory);
        mWnd->display();
        while (util::Stopwatch::getInstance()->elapsed() < std::chrono::microseconds(2000000)) {
            // Wait 2 seconds
        }
    }

    void Window::drawGameOver() {
        mWnd->clear();
        sf::Sprite gameOver;
        gameOver.setTexture(*mTextures["gameOver"]);
        gameOver.setPosition(mWnd->getSize().x / 2, mWnd->getSize().y / 2);
        gameOver.setOrigin(gameOver.getTextureRect().width / 2, gameOver.getTextureRect().height / 2);
        mWnd->draw(gameOver);
        mWnd->display();
        while (util::Stopwatch::getInstance()->elapsed() < std::chrono::microseconds(2000000)) {
            // Wait 2 seconds
        }
    }

} //namespace view