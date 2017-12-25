#include "Window.h"
#include "../Model/Enemy.h"
#include "../Model/Ship.h"
#include "../Model/Bullet.h"
#include "../Model/Obstacle.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

namespace view {
    
    Window::Window(unsigned int width, unsigned int height, const std::string &title, const std::string& background) {
        mWnd.reset(new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar));
        sf::Image i;
        i.loadFromFile(background);
        mBackgroundTexture.loadFromImage(i);
        mBackgroundTexture.setRepeated(true);
        mBackground.setTexture(mBackgroundTexture);
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
        mBackground.move(-0.5f, 0.0);
        mWnd->draw(mBackground);
        if (mBackground.getPosition().x == -(int)mWnd->getSize().x) {
            mBackground.setPosition(0, 0);

        }
    }

    void Window::drawHearts() {
        for ( int i = 0; i < mHearts; i++) {
            sf::Sprite heart;
            heart.setTexture(*mTextures["heart"]);
            heart.setPosition(0 + mWnd->getSize().x / 50 * i, mWnd->getSize().y / 12);
            mWnd->draw(heart);
        }
    }

    void Window::addEntityObserver(const std::weak_ptr<EntityObserver>& entityObserver) {
        mEntities.push_back(entityObserver);
    }

    void Window::addTexture(const std::string& name, const std::string& fileName) {
        sf::Image i;
        i.loadFromFile(fileName);
        i.createMaskFromColor(i.getPixel(0, 0));
        auto texture = std::make_shared<sf::Texture>(sf::Texture());
        texture->loadFromImage(i);
        mTextures[name] = std::move(texture);
    }

    std::shared_ptr<EntityObserver> Window::update(const std::shared_ptr<model::Entity>& entity, model::Notification what) {
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
            return entityObserver;
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
        return nullptr;
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


} //namespace view