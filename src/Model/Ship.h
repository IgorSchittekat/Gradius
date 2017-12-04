#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H
#pragma once

#include "Entity.h"

namespace model {

    class Ship : public Entity {
    public:
        explicit Ship(int lives, double speed);

        bool canFire() override;
        Notification update() override;

    private:
        int m_lives;
        int m_timeUntillNextShot;

    };

}

#endif //GRADIUS_SHIP_H
