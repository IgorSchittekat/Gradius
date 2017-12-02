#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H
#pragma once

#include <memory>
#include "Singleton.h"

namespace ctrl {

    class Transformation {
    public:
        Transformation() = default;
        void setSize(unsigned int width, unsigned int height);

        std::pair<unsigned int, unsigned int> transformCoordinates(std::pair<double, double> location) const;

        std::pair<double, double> transformSize(std::pair<unsigned int, unsigned int> size) const;

        std::pair<unsigned int, unsigned int> transformSize(std::pair<double, double> size) const;

    private:
        unsigned int m_screenWidth;
        unsigned int m_screenHeight;
    };

} // namespace ctrl

#endif //GRADIUS_TRANSFORMATION_H
