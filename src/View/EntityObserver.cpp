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
            auto textureSize = mSprite.getTexture()->getSize();
            mSprite.setScale(size.first / (float)textureSize.x, size.second / (float)textureSize.y);
            mSprite.setOrigin(mSprite.getTextureRect().width / 2, mSprite.getTextureRect().height / 2);
            mSprite.setPosition(coordinates.getX(), coordinates.getY());
        }
        else if (what == model::Notification::MOVED) {
            auto coordinates = util::Transformation::getInstance()->transformCoordinates(entity->getLocation());
            mSprite.setPosition(coordinates.getX(), coordinates.getY());
        }
    }

} // namespace view