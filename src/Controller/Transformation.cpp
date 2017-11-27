#include <cassert>
#include "Transformation.h"

namespace ctrl {

    void Transformation::setSize(unsigned int width, unsigned int height) {
        m_screenWidth = width;
        m_screenHeight = height;
    }

    std::pair<unsigned int, unsigned int> Transformation::tramsform(double x, double y) const {
        assert (x >= -4);
        assert (x <= 4);
        assert (y >= -3);
        assert (y <= 3);
        // TODO: Exception instead of assertion
        return {(x + 4) / 8.0 * m_screenWidth, (y + 3) / 6.0 * m_screenHeight};
    }

    std::pair<unsigned int, unsigned int> Transformation::tramsform(std::pair<double, double> location) const {
        return tramsform(location.first, location.second);
    }

} // namespace ctrl