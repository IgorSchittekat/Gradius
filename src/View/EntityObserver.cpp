#include <iostream>
#include "EntityObserver.h"
#include "../Controller/Singleton.h"
#include "../Controller/Transformation.h"

namespace view {


    EntityObserver::EntityObserver(const std::unique_ptr<Window>& wnd, const std::string& textureFile, const std::string& type) {
        wnd->addTexture(type, textureFile);
        m_sprite.setTexture(*wnd->getTexture(type));
    }

    EntityObserver::EntityObserver(const std::unique_ptr<Window> &wnd, const std::string &type) {
        m_sprite.setTexture(*wnd->getTexture(type));
    }

    EntityObserver::EntityObserver(const EntityObserver &rhs) {
        m_sprite.setTexture(*rhs.m_sprite.getTexture());
    }

    EntityObserver& EntityObserver::operator=(const EntityObserver &rhs) {
        m_sprite.setTexture(*rhs.m_sprite.getTexture());
        return *this;
    }

    EntityObserver::~EntityObserver() {

    }

    void EntityObserver::draw(sf::RenderWindow& wnd) {
        m_sprite.setPosition(x, y);
        m_sprite.getTexture()->getSize().x;
        wnd.draw(m_sprite);
    }

    void EntityObserver::update(const model::Entity* entity, model::Notification what) {
        if (what == model::Notification::CREATED) {
            auto coordinates = ctrl::Singleton<ctrl::Transformation>::getInstance()->tramsform(entity->getLocation());
            x = coordinates.first;
            y = coordinates.second;
            m_sprite.scale(2, 2);
            m_sprite.setOrigin(14, 7);
        }
        else if (what == model::Notification::MOVED) {
            auto coordinates = ctrl::Singleton<ctrl::Transformation>::getInstance()->tramsform(entity->getLocation());
            x = coordinates.first;
            y = coordinates.second;
        }
    }

} // namespace view