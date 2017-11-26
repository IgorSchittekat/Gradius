#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H
#pragma once

#include <memory>

namespace ctrl {

    class Transformation {
    public:
        Transformation() = default;
        void setSize(unsigned int width, unsigned int height);

        std::pair<unsigned int, unsigned int> tramsform(double x, double y) const;

    private:
        unsigned int m_screenWidth;
        unsigned int m_screenHeight;
    };

} // namespace ctrl

#endif //GRADIUS_TRANSFORMATION_H
