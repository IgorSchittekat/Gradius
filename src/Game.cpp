#include "Game.h"
#include "ConfigParser.hpp"


Game::Game() :
    wnd(sf::VideoMode(800, 600), "Gradius", sf::Style::Close | sf::Style::Titlebar) {
    ConfigParser config("../bin/config.txt");
    int lives;
    config.get("lives", lives);
    ship = new Ship(lives);
}


Game::~Game() {
    delete ship;
    ship = nullptr;
}


void Game::play() {

    while (wnd.isOpen()) {
        sf::Event event;
        while (wnd.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                wnd.close();
        }


        wnd.clear();
        update();
        ship->draw(wnd);
        wnd.display();
    }
}

void Game::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        ship->move(sf::Vector2f(0.0f, -0.5f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        ship->move(sf::Vector2f(-0.5f, 0.0f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        ship->move(sf::Vector2f(0.0f, 0.5f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        ship->move(sf::Vector2f(0.5f, 0.0f));
    }

}
