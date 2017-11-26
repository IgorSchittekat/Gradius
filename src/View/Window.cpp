#include "Window.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

namespace view {
    
    Window::Window(unsigned int width, unsigned int height, const std::string &title, const std::string& background) :
            sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar) {
        sf::Image i;
        i.loadFromFile(background);
        m_backgroundTexture.loadFromImage(i);
        m_backgroundTexture.setRepeated(true);
        m_background.setTexture(m_backgroundTexture);

        font.loadFromFile("../bin/arial.ttf");
    }

    sf::Text Window::getFPS() {
        static sf::Clock clock;
        float cTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        int fps = std::round(1 / cTime);

        std::string str = "FPS: " + std::to_string(fps);
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        text.setString(str);
        return text;
    }

    void Window::drawWindow() {
        clear();
        drawBackground();
        draw(getFPS());
        for (EntityObserver* entity : m_entities) {
            entity->draw(*this);
        }
        display();
    }

    void Window::drawBackground() {
        m_background.move(-1, 0);
        draw(m_background);
        if (m_background.getPosition().x == -(int)getSize().x) {
            m_background.setPosition(0, 0);

        }
    }

    void Window::addEntityObserver(EntityObserver* entityObserver) {
        m_entities.push_back(entityObserver);
    }


} //namespace view