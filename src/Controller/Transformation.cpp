#include <cassert>
#include "Transformation.h"

namespace ctrl {

    void Transformation::setSize(unsigned int width, unsigned int height) {
        m_screenWidth = width;
        m_screenHeight = height;
    }

    std::pair<unsigned int, unsigned int> Transformation::transformCoordinates(std::pair<double, double> location) const {
        assert (location.first >= -4);
        assert (location.first <= 4);
        assert (location.second >= -3);
        assert (location.second <= 3);
        // TODO: Exception instead of assertion
        return {(location.first + 4) / 8.0 * m_screenWidth, (location.second + 3) / 6.0 * m_screenHeight};
    }

    std::pair<double, double> Transformation::transformSize(std::pair<unsigned int, unsigned int> size) const {
        assert (size.first <= m_screenWidth);
        assert (size.second <= m_screenHeight);
        // TODO: Exception
        return {size.first / (double)m_screenWidth, size.second / (double)m_screenHeight};
    }

    std::pair<unsigned int, unsigned int> Transformation::transformSize(std::pair<double, double> size) const {
        return {size.first / 8 * m_screenWidth, size.second / 6 * m_screenHeight};
    }

} // namespace ctrl