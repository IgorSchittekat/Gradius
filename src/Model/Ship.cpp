#include "Ship.h"

namespace model {

    Ship::Ship(int lives, double speed) :
            Entity(-3, 0, 0.5, 0.25, speed),
            m_lives(lives){
    }


}