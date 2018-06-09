#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <cmath>
#include "../lib/glm/vec3.hpp"

template<typename T>
class Vec3 {
private:
    T x, y, z;
public:
    Vec3() : x{T(0)}, y{T(0)}, z{T(0)} {} //no parameter constructor
    Vec3(T t) : x{t}, y{t}, z{t} {}       //single parameter constructor
    Vec3(T x, T y, T z) : x{x}, y{y}, z{z} {} //multiple parameter constructor
    Vec3(const Vec3<T>& v) : x{v.x}, y{v.y}, z{v.z} {}

    //Scalar multiplication
    Vec3<T> operator*(const T &s) const {
        return Vec3<T>( x * s, y * s, z * s);
    }

    //Vector multiplication
    Vec3<T> operator*(const Vec3<T> &v) const {
        return Vec3<T>(x * v.x, y * v.y, z * v.z);
    }

    //Vector addition
    Vec3<T> operator+(const Vec3<T> &v) const {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3<T> operator+=(const Vec3<T> &v) const {
        Vec3(x += v.x, y += v.y, z += v.z);
        return *this;
    }

    //Vector subtraction
    Vec3<T> operator-(const Vec3<T> &v) const {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    Vec3<T> operator-=(const Vec3<T> &v) const {
        Vec3(x -= v.x, y -= v.y, z -= v.z);
        return *this;
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

    //May need this for Lab4b
    glm::vec3 Vec3_To_glm(const Vec3<T> &v) {
        return glm::vec3( v.x, v.y, v.z);
    }

    friend std::ostream & operator << (std::ostream &os, const Vec3<T> &v)
    {
        os << "[" << v.x << " " << v.y << " " << v.z << "]";
        return os;
    }
};

#endif //RAYTRACER_VEC3_H
