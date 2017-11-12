#include <iostream>
#include "Ship.h"

Ship::Ship() {
    std::cout << "Constructor Ship" << std::endl;
    texture.loadFromFile("../assets/Gradius_Sprite.jpg");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(260, 0, 30, 20));
    sprite.scale(2, 2);
}

void Ship::draw(sf::RenderWindow &wnd) const {
    wnd.draw(sprite);
}

void Ship::move(const sf::Vector2f& direction) {
    sprite.move(direction);
}
