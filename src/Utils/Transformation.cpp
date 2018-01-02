#include <cassert>
#include "Transformation.h"

namespace util {

    void Transformation::setSize(unsigned int width, unsigned int height) {
        mScreenWidth = width;
        mScreenHeight = height;
    }

    Vec2u Transformation::transformCoordinates(Vec2d location) const {
        return {static_cast<unsigned int>((location.getX() + 4) / 8.0 * mScreenWidth),
                static_cast<unsigned int>((location.getY() + 3) / 6.0 * mScreenHeight)};
    }

    std::pair<double, double> Transformation::transformSize(std::pair<unsigned int, unsigned int> size) const {
        return {size.first / (double)mScreenWidth, size.second / (double)mScreenHeight};
    }

    std::pair<unsigned int, unsigned int> Transformation::transformSize(std::pair<double, double> size) const {
        return {size.first / 8 * mScreenWidth, size.second / 6 * mScreenHeight};
    }

} // namespace util