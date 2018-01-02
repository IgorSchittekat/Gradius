#ifndef VEC2_H
#define VEC2_H
#pragma once

#include <cmath>

namespace util {

    template<typename T>
    class Vec2 {
    public:
        /**
         * @brief Constructor
         * @param x : X value
         * @param y : Y value
         */
        Vec2(T x, T y) : mX(x), mY(y) {}

        /**
         * @brief Add 2 vectors
         * @param rhs : Vector to be added
         * @return Sum
         */
        Vec2 operator+(const Vec2& rhs) const { return Vec2(mX + rhs.mX, mY + rhs.mY); }

        /**
         * @brief Subtract 2 vectors
         * @param rhs : Vector to be subtracted
         * @return Difference
         */
        Vec2 operator-(const Vec2& rhs) const { return Vec2(mX - rhs.mX, mY - rhs.mY); }

        /**
         * @brief Multiply 2 Vectors
         * @param rhs : Vector to be multiplied
         * @return Multiplication
         */
        Vec2 operator*(const Vec2& rhs) const { return Vec2(mX * rhs.mX, mY * rhs.mY); }

        /**
         * @brief Add vector to this one
         * @param rhs : Vector to be added
         * @return *this
         */
        Vec2& operator+=(const Vec2& rhs) {
            mX += rhs.mX;
            mY += rhs.mY;
            return *this;
        }

        /**
         * @brief Subtract vector from this one
         * @param rhs : Vector to be subtracted
         * @return *this
         */
        Vec2& operator-=(const Vec2& rhs) {
            mX -= rhs.mX;
            mY -= rhs.mY;
            return *this;
        }

        /**
         * @brief Add T to x and y
         * @param t : Element of T
         * @return Sum
         */
        Vec2 operator+(T t) const { return Vec2(mX + t, mY + t); }

        /**
         * @brief Subtract T from x and y
         * @param t : Element of T
         * @return Difference
         */
        Vec2 operator-(T t) const { return Vec2(mX - t, mY - t); }

        /**
         * @brief Multiply x and y with T
         * @param t : Element of T
         * @return Multiplication
         */
        Vec2 operator*(T t) const { return Vec2(mX * t, mY * t); }

        /**
         * @brief operator==
         * @param rhs : Vector to be checked
         * @return bool if they are equal
         */
        bool operator==(const Vec2& rhs) const { return mX == rhs.mX && mY == rhs.mY; }

        /**
         * @brief operator!=
         * @param rhs : Vector to be checked
         * @return bool if they are not equal
         */
        bool operator!=(const Vec2& rhs) const { return !(*this == rhs); }

        /**
         * @brief get value of x
         * @return x
         */
        T getX() const { return mX; }

        /**
         * @brief get value of y
         * @return y
         */
        T getY() const { return mY; }

        /**
         * @brief get length of the vector
         * @return length of the vector
         */
        T length() const { return std::sqrt((mX * mX) + (mY * mY)); }

        /**
         * @brief normalise the vector
         * @return *this
         */
        Vec2& normalise() {
            const T length = this->length();
            if (length != 0) {
                mX /= length;
                mY /= length;
            }
            return *this;
        }

        /**
         * @brief print the vector to ostream
         * @param os : outputstream
         * @param vec2 : vector to be printed
         * @return outputstream
         */
        friend std::ostream& operator<<(std::ostream& os, const Vec2& vec2) {
            os << vec2.mX << ' ' << vec2.mY;
            return os;
        }

    private:
        /**
         * @brief x
         */
        T mX;
        /**
         * @brief y
         */
        T mY;
    };

    /**
     * @brief predefined vector of ints
     */
    using Vec2i = Vec2<int>;
    /**
     * @brief predefined vector of floats
     */
    using Vec2f = Vec2<float>;
    /**
     * @brief predefined vector of doubles
     */
    using Vec2d = Vec2<double>;
    /**
     * @brief predefined vector of unsigned int
     */
    using Vec2u = Vec2<unsigned int>;

} //namespace util


#endif //VEC2_H
