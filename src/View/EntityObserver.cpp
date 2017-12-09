#include <iostream>
#include "EntityObserver.h"
#include "../Utils/Singleton.h"
#include "../Utils/Transformation.h"

namespace view {


    EntityObserver::EntityObserver(const std::shared_ptr<Window>& wnd, const std::string& textureFile, const std::string& type) {
        wnd->addTexture(type, textureFile);
        m_sprite.setTexture(*wnd->getTexture(type), true);
    }

    EntityObserver::EntityObserver(const std::shared_ptr<Window> &wnd, const std::string &type) {
        m_sprite.setTexture(*wnd->getTexture(type), true);
    }
    EntityObserver::EntityObserver(const sf::Texture& texture) {
        m_sprite.setTexture(texture, true);
    }

    EntityObserver::EntityObserver(const EntityObserver &rhs) {
        m_sprite.setTexture(*rhs.m_sprite.getTexture(), true);
        m_rect = rhs.m_rect;
    }

    EntityObserver& EntityObserver::operator=(const EntityObserver &rhs) {
        m_sprite.setTexture(*rhs.m_sprite.getTexture(), true);
        m_rect = rhs.m_rect;
        return *this;
    }

    EntityObserver::~EntityObserver() {
    }

    void EntityObserver::draw(sf::RenderWindow& wnd) {
        m_sprite.setPosition(m_rect.left + m_rect.width / 2, m_rect.top + m_rect.height / 2);
        wnd.draw(m_sprite);
    }

    void EntityObserver::update(const model::Entity* entity, model::Notification what) {
        if (what == model::Notification::CREATED) {
            auto coordinates = util::Transformation::getInstance()->transformCoordinates(entity->getLocation());
            auto size = util::Transformation::getInstance()->transformSize(entity->getSize());
            m_rect.width = size.first;
            m_rect.height = size.second;
            m_rect.left = coordinates.first - m_rect.width / 2;
            m_rect.top = coordinates.second - m_rect.height / 2;
            auto textureSize = m_sprite.getTexture()->getSize();
            m_sprite.setScale(m_rect.width / (float)textureSize.x, m_rect.height / (float)textureSize.y);
            m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
        }
        else if (what == model::Notification::MOVED) {
            auto coordinates = util::Transformation::getInstance()->transformCoordinates(entity->getLocation());
            m_rect.left = coordinates.first - m_rect.width / 2;
            m_rect.top = coordinates.second - m_rect.height / 2;
        }
    }

} // namespace view