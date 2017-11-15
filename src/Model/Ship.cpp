#include <iostream>
#include "Ship.h"

Ship::Ship(int lives) :
    Entity(),
    lives(lives) {
    //texture.loadFromFile("../images/Ship.png");
    sf::Image i;
    i.loadFromFile("../images/Ship.png");
    i.createMaskFromColor(i.getPixel(0,0));
    texture.loadFromImage(i);
    sprite.setTexture(texture);
    sprite.scale(2, 2);
}

void Ship::draw(sf::RenderWindow& wnd) const {
    wnd.draw(sprite);
}

void Ship::move(const sf::Vector2f& direction) {
    sprite.move(direction);
}


