#ifndef GRADIUS_TRANSFORMATION_H
#define GRADIUS_TRANSFORMATION_H
#pragma once

#include <memory>
#include "Singleton.h"
#include "Vec2.h"

namespace util {

    class Transformation : public Singleton<Transformation> {
        friend class Singleton<Transformation>;
    public:
        /**
         * @brief set the size of the window
         * @param width : width of the window
         * @param height : height of the window
         */
        void setSize(unsigned int width, unsigned int height);

        /**
         * @brief transform gamecoordinates to the screenpixels
         * @param location : coordinates in [-4, 4], [-3, 3] coordinatesystem
         * @return pixelcoordinates
         */
        Vec2u transformCoordinates(Vec2d location) const;

        /**
         * transform the size of an object
         * @param size : size in pixelcoordinates
         * @return size in [-4, 4], [-3, 3] coordinatesystem
         */
        std::pair<double, double> transformSize(std::pair<unsigned int, unsigned int> size) const;

        /**
         * transform the size of an object
         * @param size : size in [-4, 4], [-3, 3] coordinatesystem
         * @return size in pixelcoordinates
         */
        std::pair<unsigned int, unsigned int> transformSize(std::pair<double, double> size) const;

    private:
        /**
         * @brief Constructor.
         */
        Transformation() = default;

    private:
        /**
         * @brief Width of the screen
         */
        unsigned int mScreenWidth;
        /**
         * @brief Height of the screen
         */
        unsigned int mScreenHeight;
    };

} // namespace util

#endif //GRADIUS_TRANSFORMATION_H
