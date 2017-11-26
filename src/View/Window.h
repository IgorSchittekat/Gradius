#ifndef GRADIUS_WORLD_H
#define GRADIUS_WORLD_H
#pragma once

#include <SFML/Graphics.hpp>
#include "EntityObserver.h"


namespace view {

    class EntityObserver;

class Window : public sf::RenderWindow {
public:
    Window(unsigned int width, unsigned int height, const std::string &title, const std::string& background);

    void drawWindow();

    void drawBackground();

    sf::Text getFPS();

    void addEntityObserver(EntityObserver* entityObserver);

private:
    sf::Texture m_backgroundTexture;
    sf::Sprite m_background;
    sf::Font font;
    std::vector<EntityObserver*> m_entities;
};

}


#endif //GRADIUS_WORLD_H
