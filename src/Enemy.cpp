#include "Enemy.h"

Enemy::Enemy() :
    Entity() {
    texture.loadFromFile("../images/Enemy1.png");

    sprite.setTexture(texture);
    sprite.scale(2, 2);
    sprite.setPosition(100, 100);
}

void Enemy::draw(sf::RenderWindow& wnd) const {
    wnd.draw(sprite);
}