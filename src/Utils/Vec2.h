#ifndef GRADIUS_VEC2_H
#define GRADIUS_VEC2_H
#pragma once

namespace util {

    template<typename T>
    class Vec2 {
    public:
        Vec2(T x, T y) : mX(x), mY(y) {}

        Vec2 operator+(const Vec2& rhs) { return Vec2(mX + rhs.mX, mY + rhs.mY); }

        Vec2 operator-(const Vec2& rhs) { return Vec2(mX - rhs.mX, mY - rhs.mY); }

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

        Vec2 operator+(T t) { return Vec2(mX + t, mY + t); }

        Vec2 operator-(T t) { return Vec2(mX - t, mY - t); }

        Vec2 operator*(T t) { return Vec2(mX * t, mY * t); }

        bool operator==(const Vec2& rhs) const { return mX == rhs.mX && mY == rhs.mY; }

        T getX() const { return mX; }

        T getY() const { return mY; }

    private:
        T mX;
        T mY;
    };

#define Vec2i Vec2<int>
#define Vec2f Vec2<float>
#define Vec2d Vec2<double>
#define Vec2u Vec2<unsigned int>

} //namespace util


#endif //GRADIUS_VEC2_H
