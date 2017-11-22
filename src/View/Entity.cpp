#include "Entity.h"

namespace view {



Entity::Entity(const std::string& textureFile) {
    sf::Image i;
    i.loadFromFile(textureFile);
    i.createMaskFromColor(i.getPixel(0, 0));
    m_texture.loadFromImage(i);
    m_sprite.setTexture(m_texture);
    m_sprite.scale(2, 2);
}

Entity::Entity(const Entity &rhs) {

}

Entity &Entity::operator=(const Entity &rhs) {
    return *this;
}

Entity::~Entity() {

}

void Entity::draw(view::World& world, double x, double y) {
    m_sprite.setPosition(x, y);
    world.draw(m_sprite);
}


    void Entity::control() const {

    }

} //namespace view