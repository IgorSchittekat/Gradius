#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include <SFML/Graphics.hpp>


class Ship {
public:


    Ship();
    Ship(const Ship& rhs) = delete;
    Ship& operator=(const Ship& rhs) = delete;

    void draw(sf::RenderWindow& wnd) const;
    void move(const sf::Vector2f& direction);

private:
    sf::Texture texture;
    sf::Sprite sprite;

};


#endif //GRADIUS_SHIP_H
