#ifndef GRADIUS_ENTITY_H
#define GRADIUS_ENTITY_H

#include <SFML/Graphics.hpp>

namespace model {

enum Direction {UP, DOWN, LEFT, RIGHT};

class Entity {
public:
    Entity();
    Entity(double x, double y, double speed);
    virtual void move(Direction dir);

protected:
    double m_x;
    double m_y;
    double m_speed;
};

} //namespace model

#endif //GRADIUS_ENTITY_H
