#ifndef GRADIUS_SHIP_H
#define GRADIUS_SHIP_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace model {

    class Ship : public Entity {
    public:
        explicit Ship(int lives, double speed);

        Ship(const Ship &rhs) = delete;

        Ship &operator=(const Ship &rhs) = delete;


    private:
        int m_lives;

    };

}

#endif //GRADIUS_SHIP_H
