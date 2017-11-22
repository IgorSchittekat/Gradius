#ifndef GRADIUS_ENEMY_H
#define GRADIUS_ENEMY_H


#include "Entity.h"

namespace model {

    class Enemy : public Entity {
    public:
        Enemy();

        void draw(sf::RenderWindow &wnd) const;

    private:

    };

}

#endif //GRADIUS_ENEMY_H
