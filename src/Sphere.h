#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <string>

#include "RGB_Space.h"
#include "Ray.h"
#include "Vec3.h"

class Sphere {
private:
    float radius;
    Vec3<float> center;
    RGB_Space rgb;
    double ka, kd, ks, exponent;
    float reflectance;
    float refraction;
    float transmittance;
    std::string material;

public:
    Sphere(float radius, float x, float y, float z, RGB_Space rgb, double ka, double kd, double exponent, float reflectance, float transmittance, float refraction, std::string material);
};


#endif //RAYTRACER_SPHERE_H
