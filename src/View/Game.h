#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H

#include <SFML/Graphics.hpp>
#include "../Model/Ship.h"
#include "../Model/Enemy.h"
#include <list>

class Game {
public:
    Game();
    Game(const Game& rhs) = delete;
    Game& operator=(const Game& rhs) = delete;
    ~Game();


    void update();
    void play();

private:
    sf::RenderWindow wnd;
    Ship* ship;
    std::list<Enemy*> enemies;
};


#endif //GRADIUS_GAME_H
