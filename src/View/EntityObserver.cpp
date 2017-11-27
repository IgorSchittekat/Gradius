#include <iostream>
#include "EntityObserver.h"
#include "../Controller/Singleton.h"
#include "../Controller/Transformation.h"

namespace view {


    EntityObserver::EntityObserver(const std::string& textureFile) {
        sf::Image i;
        i.loadFromFile(textureFile);
        i.createMaskFromColor(i.getPixel(0, 0));
        m_texture.loadFromImage(i);
        m_sprite.setTexture(m_texture);
    }

    EntityObserver::EntityObserver(const EntityObserver &rhs) {

    }

    EntityObserver& EntityObserver::operator=(const EntityObserver &rhs) {
        return *this;
    }

    EntityObserver::~EntityObserver() {

    }

    void EntityObserver::draw(Window& wnd) {
        m_sprite.setPosition(x, y);
        wnd.draw(m_sprite);
    }

    void EntityObserver::update(const model::Entity* entity, Notification what) {
        if (what == Notification::CREATED) {
            auto coordinates = ctrl::Singleton<ctrl::Transformation>::getInstance()->tramsform(entity->getLocation());
            x = coordinates.first;
            y = coordinates.second;
            m_sprite.scale(2, 2);
            m_sprite.setOrigin(14, 7);
        }
        else if (what == Notification::MOVED) {
            auto coordinates = ctrl::Singleton<ctrl::Transformation>::getInstance()->tramsform(entity->getLocation());
            x = coordinates.first;
            y = coordinates.second;
        }
    }

} // namespace view