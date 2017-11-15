#include "Game.h"


Game::Game() :
    wnd(sf::VideoMode(800, 600), "Gradius", sf::Style::Close | sf::Style::Titlebar) {
    int lives;
    ship = new Ship(5);
}


Game::~Game() {
    delete ship;
    ship = nullptr;
    for (Enemy* enemy : enemies) {
        delete enemy;
        enemy = nullptr;
    }
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
        for (Enemy* enemy : enemies) {
            enemy->draw(wnd);
        }
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
        Enemy* e = new Enemy();
        enemies.push_back(e);

    }

}
