#include "Ship.h"

namespace model {

    Ship::Ship(int lives, double speed) :
            Entity(0, 0, speed),
            m_lives(lives){
    }


}