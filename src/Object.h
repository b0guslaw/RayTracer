#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include <vector>
#include <iostream>
#include <array>

#include "Ray.h"

class Object {
private:
    std::vector<Vec3f> vert;
public:
    Object() = delete;
    Object(std::vector<std::array<double,3>>);
    void pretty_print();
    double intersect(Ray);
    float ka, kd, ks, exponent;
    float reflectance, transmittance, iof;
    Vec3f color, normal;
};


#endif //RAYTRACER_OBJECT_H
