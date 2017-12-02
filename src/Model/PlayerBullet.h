#ifndef GRADIUS_PLAYERBULLET_H
#define GRADIUS_PLAYERBULLET_H
#pragma once

#include <iostream>
#include "Bullet.h"

namespace model {

    class PlayerBullet : public Bullet {
    public:

        PlayerBullet(const std::shared_ptr<Entity>& firingEntity, double speed);

        Notification update() override;

    private:

    };

}

#endif //GRADIUS_PLAYERBULLET_H
