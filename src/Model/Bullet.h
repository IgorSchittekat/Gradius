#ifndef GRADIUS_BULLET_H
#define GRADIUS_BULLET_H
#pragma once

#include "Entity.h"

namespace model {
    class Level;

    class Bullet : public Entity {
    public:
        Bullet() = default;
        Bullet(const std::shared_ptr<Entity>& firingEntity, double speed);

        ~Bullet() override = default;

        Notification move(Direction Dir) override;

        Notification update() override;
    private:

    };

}

#endif //GRADIUS_BULLET_H
