#include <iostream>
#include "EntityObserver.h"
#include "../Utils/Singleton.h"
#include "../Utils/Transformation.h"

namespace view {

    EntityObserver::EntityObserver(const sf::Texture& texture) {
        mSprite.setTexture(texture, true);
    }

    void EntityObserver::draw(sf::RenderWindow& wnd) {
        wnd.draw(mSprite);
    }

    void EntityObserver::update(const model::Entity* entity, model::Notification what) {
        if (what == model::Notification::CREATED) {
            auto coordinates = util::Transformation::getInstance()->transformCoordinates(entity->getLocation());
            auto size = util::Transformation::getInstance()->transformSize(entity->getSize());
            mRect.width = size.first;
            mRect.height = size.second;
            mRect.left = coordinates.getX() - mRect.width / 2;
            mRect.top = coordinates.getY() - mRect.height / 2;
            auto textureSize = mSprite.getTexture()->getSize();
            mSprite.setScale(mRect.width / (float)textureSize.x, mRect.height / (float)textureSize.y);
            mSprite.setOrigin(mSprite.getTextureRect().width / 2, mSprite.getTextureRect().height / 2);
            mSprite.setPosition(mRect.left + mRect.width / 2, mRect.top + mRect.height / 2);
        }
        else if (what == model::Notification::MOVED) {
            auto coordinates = util::Transformation::getInstance()->transformCoordinates(entity->getLocation());
            mRect.left = coordinates.getX() - mRect.width / 2;
            mRect.top = coordinates.getY() - mRect.height / 2;
            mSprite.setPosition(mRect.left + mRect.width / 2, mRect.top + mRect.height / 2);
        }
    }

} // namespace view