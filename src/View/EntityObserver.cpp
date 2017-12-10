#include <iostream>
#include "EntityObserver.h"
#include "../Utils/Singleton.h"
#include "../Utils/Transformation.h"

namespace view {


    EntityObserver::EntityObserver(const std::shared_ptr<Window>& wnd, const std::string& textureFile, const std::string& type) {
        wnd->addTexture(type, textureFile);
        mSprite.setTexture(*wnd->getTexture(type), true);
    }

    EntityObserver::EntityObserver(const std::shared_ptr<Window> &wnd, const std::string &type) {
        mSprite.setTexture(*wnd->getTexture(type), true);
    }
    EntityObserver::EntityObserver(const sf::Texture& texture) {
        mSprite.setTexture(texture, true);
    }

    EntityObserver::EntityObserver(const EntityObserver &rhs) {
        mSprite.setTexture(*rhs.mSprite.getTexture(), true);
        mRect = rhs.mRect;
    }

    EntityObserver& EntityObserver::operator=(const EntityObserver &rhs) {
        mSprite.setTexture(*rhs.mSprite.getTexture(), true);
        mRect = rhs.mRect;
        return *this;
    }

    EntityObserver::~EntityObserver() {
    }

    void EntityObserver::draw(sf::RenderWindow& wnd) {
        mSprite.setPosition(mRect.left + mRect.width / 2, mRect.top + mRect.height / 2);
        wnd.draw(mSprite);
    }

    void EntityObserver::update(const model::Entity* entity, model::Notification what) {
        if (what == model::Notification::CREATED) {
            auto coordinates = util::Transformation::getInstance()->transformCoordinates(entity->getLocation());
            auto size = util::Transformation::getInstance()->transformSize(entity->getSize());
            mRect.width = size.first;
            mRect.height = size.second;
            mRect.left = coordinates.first - mRect.width / 2;
            mRect.top = coordinates.second - mRect.height / 2;
            auto textureSize = mSprite.getTexture()->getSize();
            mSprite.setScale(mRect.width / (float)textureSize.x, mRect.height / (float)textureSize.y);
            mSprite.setOrigin(mSprite.getTextureRect().width / 2, mSprite.getTextureRect().height / 2);
        }
        else if (what == model::Notification::MOVED) {
            auto coordinates = util::Transformation::getInstance()->transformCoordinates(entity->getLocation());
            mRect.left = coordinates.first - mRect.width / 2;
            mRect.top = coordinates.second - mRect.height / 2;
        }
    }

} // namespace view