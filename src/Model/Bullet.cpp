#include "Bullet.h"


namespace model {

    Bullet::Bullet(const std::shared_ptr<model::Entity>& firingEntity, double speed) :
        Entity(firingEntity->getLocation().first, firingEntity->getLocation().second, 0.25, 0.125, speed) {
    }

} // namespace model

