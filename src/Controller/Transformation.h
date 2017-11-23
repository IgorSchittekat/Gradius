#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H


#include <memory>

class Transformation {
public:

    static std::shared_ptr<Transformation> getInstance();

private:
    Transformation() = default;
    static std::shared_ptr<Transformation> m_instance;

};


#endif //GRADIUS_TRANSFORMATION_H
