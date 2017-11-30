#include "Window.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

namespace view {
    
    Window::Window(unsigned int width, unsigned int height, const std::string &title, const std::string& background) {
        m_wnd.reset(new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar));
        sf::Image i;
        i.loadFromFile(background);
        m_backgroundTexture.loadFromImage(i);
        m_backgroundTexture.setRepeated(true);
        m_background.setTexture(m_backgroundTexture);

        font.loadFromFile("../bin/arial.ttf");
    }

    bool Window::isOpen() {
        sf::Event event {};
        while (m_wnd->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_wnd->close();
        }
        return m_wnd->isOpen();
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
        m_wnd->clear();
        drawBackground();
        m_wnd->draw(getFPS());
        for (const std::shared_ptr<EntityObserver>& entity : m_entities) {
            entity->draw(*m_wnd);
        }
        m_wnd->display();
    }

    void Window::drawBackground() {
        m_background.move(-1, 0);
        m_wnd->draw(m_background);
        if (m_background.getPosition().x == -(int)m_wnd->getSize().x) {
            m_background.setPosition(0, 0);

        }
    }

    void Window::addEntityObserver(const std::shared_ptr<EntityObserver>& entityObserver) {
        m_entities.push_back(entityObserver);
    }

    void Window::addTexture(const std::string& name, const std::string& fileName) {
        sf::Image i;
        i.loadFromFile(fileName);
        i.createMaskFromColor(i.getPixel(0, 0));
        auto texture = std::make_shared<sf::Texture>(sf::Texture());
        texture->loadFromImage(i);
        m_textures[name] = std::move(texture);
    }

    std::shared_ptr<sf::Texture> Window::getTexture(const std::string &name) {
        return m_textures[name];
    }


} //namespace view