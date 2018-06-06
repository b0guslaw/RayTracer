#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <string>
#include "RGB.h"

class Sphere {
private:
    double radius;
    double x, y , z;
    RGB rgb;
    double ka, kd, ks, exponent;
    double reflectance;
    double refraction;
    double transmittance;
    double iof;
    std::string material;
public:
    Sphere(double radius, double x, double y, double z, RGB rgb,double ka, double ks, double exponent, double reflectance, double transmittance, double refraction, std::string material);
};


#endif //RAYTRACER_SPHERE_H
