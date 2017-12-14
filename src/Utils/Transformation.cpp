#include <cassert>
#include "Transformation.h"

namespace util {

    void Transformation::setSize(unsigned int width, unsigned int height) {
        mScreenWidth = width;
        mScreenHeight = height;
    }

    std::pair<unsigned int, unsigned int> Transformation::transformCoordinates(Vec2d location) const {
//        assert (location.first >= -4);
//        assert (location.first <= 4);
//        assert (location.second >= -3);
//        assert (location.second <= 3);
        // TODO: Exception instead of assertion
        return {(location.getX() + 4) / 8.0 * mScreenWidth, (location.getY() + 3) / 6.0 * mScreenHeight};
    }

    std::pair<double, double> Transformation::transformSize(std::pair<unsigned int, unsigned int> size) const {
//        assert (size.first <= mScreenWidth);
//        assert (size.second <= mScreenHeight);
        // TODO: Exception
        return {size.first / (double)mScreenWidth, size.second / (double)mScreenHeight};
    }

    std::pair<unsigned int, unsigned int> Transformation::transformSize(std::pair<double, double> size) const {
        return {size.first / 8 * mScreenWidth, size.second / 6 * mScreenHeight};
    }

} // namespace util