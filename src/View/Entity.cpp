#include "Entity.h"

namespace view {



Entity::Entity(model::Entity* entity) :
    m_entity(entity) {
}

Entity::Entity(const Entity &rhs) {

}

Entity &Entity::operator=(const Entity &rhs) {
    return *this;
}

Entity::~Entity() {

}

void Entity::draw(sf::RenderWindow& wnd) const {
    wnd.draw(m_sprite);
}


} //namespace view