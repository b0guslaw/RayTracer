#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <cmath>
#include <ostream>

/**
 * This header only template class is used for vector calculations.
 */
template<typename T>
class Vec3 {
private:


public:
    T x, y, z;
    Vec3() : x{T(0)}, y{T(0)}, z{T(0)} {} //no parameter constructor
    Vec3(T t) : x{t}, y{t}, z{t} {}       //single parameter constructor
    Vec3(T x, T y, T z) : x{x}, y{y}, z{z} {} //multiple parameter constructor
    Vec3(const Vec3<T>& v) : x{v.x}, y{v.y}, z{v.z} {}

    //Scalar multiplication
    Vec3<T> operator*(const T &s) const {
        return Vec3<T>( x * s, y * s, z * s);
    }

    //Scalar Division
    Vec3<T> operator/(const T &s) const {
        return Vec3<T>( x / s, y / s, z / s);
    }

    //Vector multiplication
    Vec3<T> operator*(const Vec3<T> &v) const {
        return Vec3<T>(x * v.x, y * v.y, z * v.z);
    }

    //Vector addition
    Vec3<T> operator+(const Vec3<T> &v) const {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    void operator+=(const Vec3<T> &v)  {
        x+=v.getX();
        y+=v.getY();
        z+=v.getZ();
    }

    //Vector subtraction
    Vec3<T> operator-(const Vec3<T> &v) const {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    void operator-=(const Vec3<T> &v) const {
        x-=v.getX();
        y-=v.getY();
        z-=v.getZ();
    }

    //Vector length
    T len() const {
        return sqrt( (x * x + y * y + z * z) );
    }

    Vec3<T> operator-() const {
        return Vec3<T>(-x, -y, -z);
    }

    //Dot operator
    T dot(const Vec3<T> &v) const {
        return (x * v.x + y * v.y + z * v.z);
    }

    Vec3<T> cross(const Vec3<T> &v) const {
        return (
                y * v.z - z * v.y,
                z * v.x - x * v.z,
                x * v.y - y * v.x
                );
    }

    friend std::ostream &operator<<(std::ostream &os, const Vec3<T> &v) {
        os << "[" << v.x << " " << v.y << " " << v.z << "]";
        return os;
    }

    Vec3<T> Unit() {
        T u = len();
        return  {x/u, y/u, z/u};
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    T getZ() const {
        return z;
    }
};

#endif //RAYTRACER_VEC3_H
