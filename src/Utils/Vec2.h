#ifndef VEC2_H
#define VEC2_H
#pragma once

#include <cmath>

namespace util {

    template<typename T>
    class Vec2 {
    public:
        Vec2(T x, T y) : mX(x), mY(y) {}

        Vec2 operator+(const Vec2& rhs) const { return Vec2(mX + rhs.mX, mY + rhs.mY); }

        Vec2 operator-(const Vec2& rhs) const { return Vec2(mX - rhs.mX, mY - rhs.mY); }

        Vec2 operator*(const Vec2& rhs) const { return Vec2(mX * rhs.mX, mY * rhs.mY); }

        Vec2& operator+=(const Vec2& rhs) {
            mX += rhs.mX;
            mY += rhs.mY;
            return *this;
        }

        Vec2& operator-=(const Vec2& rhs) {
            mX -= rhs.mX;
            mY -= rhs.mY;
            return *this;
        }

        Vec2 operator+(T t) const { return Vec2(mX + t, mY + t); }

        Vec2 operator-(T t) const { return Vec2(mX - t, mY - t); }

        Vec2 operator*(T t) const { return Vec2(mX * t, mY * t); }

        bool operator==(const Vec2& rhs) const { return mX == rhs.mX && mY == rhs.mY; }

        bool operator!=(const Vec2& rhs) const { return !(*this == rhs); }

        T getX() const { return mX; }

        T getY() const { return mY; }

        T length() const { return std::sqrt((mX * mX) + (mY * mY)); }

        Vec2& normalise() {
            const T length = this->length();
            if (length != 0) {
                mX /= length;
                mY /= length;
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec2& vec2) {
            os << vec2.mX << ' ' << vec2.mY;
            return os;
        }

    private:
        T mX;
        T mY;
    };

    using Vec2i = Vec2<int>;
    using Vec2f = Vec2<float>;
    using Vec2d = Vec2<double>;
    using Vec2u = Vec2<unsigned int>;

} //namespace util


#endif //VEC2_H
