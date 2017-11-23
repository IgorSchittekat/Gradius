#include "Transformation.h"

std::shared_ptr<Transformation> Transformation::m_instance = nullptr;

std::shared_ptr<Transformation> Transformation::getInstance() {
    if (!m_instance) {
        m_instance = std::make_shared(Transformation());
    }
    return m_instance;
}


