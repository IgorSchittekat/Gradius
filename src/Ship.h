#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include <SFML/Graphics.hpp>
#include "Entity.h"


class Ship : public Entity {
public:
    explicit Ship(int lives);
    Ship(const Ship& rhs) = delete;
    Ship& operator=(const Ship& rhs) = delete;

    void draw(sf::RenderWindow& wnd) const override;
    void move(const sf::Vector2f& direction);

private:
    int lives;
};


#endif //GRADIUS_SHIP_H
