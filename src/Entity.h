#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:

    virtual void draw(sf::RenderWindow &wnd) const = 0;

protected:
    sf::Texture texture;

};


#endif //GRADIUS_ENTITY_H
