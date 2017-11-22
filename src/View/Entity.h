#ifndef GRADIUS_VIEW_ENTITY_H
#define GRADIUS_VIEW_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../Model/Entity.h"
#include "../Model/Ship.h"

namespace view {

class Entity {
public:
    Entity(const std::string& textureFile);

    Entity(const Entity &rhs);

    Entity &operator=(const Entity &rhs);

    ~Entity();

    void draw(sf::RenderWindow& wnd) const;

    void control() const;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

} //namespace view

#endif //GRADIUS_VIEW_ENTITY_H
