#ifndef GRADIUS_VIEW_ENTITY_H
#define GRADIUS_VIEW_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../Model/Entity.h"
#include "../Model/Ship.h"
#include "World.h"

namespace view {

    class World;

class Entity {
public:
    Entity(const std::string& textureFile);

    Entity(const Entity &rhs);

    Entity &operator=(const Entity &rhs);

    ~Entity();

    void draw(view::World& world, double x, double y);

    void control() const;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

} //namespace view

#endif //GRADIUS_VIEW_ENTITY_H
