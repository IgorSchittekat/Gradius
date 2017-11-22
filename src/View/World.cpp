#include "World.h"
#include "../Controller/Controller.h"
#include <iostream>

namespace view {

    World::World(sf::VideoMode mode, const std::string &title, const std::string& background) :
            sf::RenderWindow(mode, title) {
        sf::Image i;
        i.loadFromFile(background);
        m_backgroundTexture.loadFromImage(i);
        m_backgroundTexture.setRepeated(true);
        m_background.setTexture(m_backgroundTexture);
    }


    void World::setController(std::unique_ptr<ctrl::Controller> controller) {
        m_controller = std::move(controller);
    }


    void World::update() {
        drawBackground();
        m_controller->control();
    }

    void World::drawBackground() {
        m_background.move(-1, 0);
        this->draw(m_background);
        if (m_background.getPosition().x == -(int)getSize().x) {
            m_background.setPosition(0, 0);

        }
    }

} //namespace view