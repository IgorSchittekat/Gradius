#include "Controller/Parser.h"
#include "View/World.h"
#include <iostream>
#include "Controller/Parser.h"
#include "Model/Enemy.h"
#include "Controller/Stopwatch.h"


int main() {
    view::World* game = ctrl::Parser::parseWorld();







    while (game->isOpen()) {
        sf::Event event{};
        while (game->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game->close();
        }


        game->clear(sf::Color::White);
        game->update();
        game->display();


    }

    return 0;
}