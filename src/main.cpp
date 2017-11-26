#include "Controller/Parser.h"
#include "View/World.h"
#include <iostream>
#include "Controller/Parser.h"
#include "Model/Enemy.h"
#include "Controller/Singleton.h"


int main() {
    view::World* game = ctrl::Parser::parseWorld();


    ctrl::Stopwatch* stopwatch = ctrl::Singleton<ctrl::Stopwatch>::getInstance();


    while (game->isOpen()) {
        stopwatch->restart();
        sf::Event event {};
        while (game->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game->close();
        }


        game->clear(sf::Color::White);
        game->update();
        game->display();


        while (stopwatch->elapsed() < std::chrono::microseconds(16666)) {
            // Wait time to run at 60 fps at all computers
        }

    }

    return 0;
}