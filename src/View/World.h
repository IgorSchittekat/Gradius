#ifndef GRADIUS_WORLD_H
#define GRADIUS_WORLD_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "../Controller/Controller.h"

namespace view {

class World : public sf::RenderWindow {
public:
    World() : sf::RenderWindow() {};

    World(sf::VideoMode mode, const std::string &title, const std::string& background);

    World(const World &rhs) = delete;

    World &operator=(const World &rhs) = delete;

    ~World() {};

    void setShip(std::unique_ptr<Entity> ship);

    void addEntity(Entity* entity);

    void update();

    void drawBackground();

    void setController(std::unique_ptr<ctrl::Controller> controller);

private:
    sf::Texture m_backgroundTexture;
    sf::Sprite m_background;
    std::unique_ptr<ctrl::Controller> m_controller;
};

}


#endif //GRADIUS_WORLD_H
