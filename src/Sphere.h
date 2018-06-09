#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <string>

#include "RGB_Space.h"
#include "Ray.h"
#include "Vec3.h"

typedef Vec3<float> Vec3f;

class Sphere {
private:
    Vec3f center;
    float radius;
    RGB_Space rgb;
    double ka, kd, ks, exponent;
    float reflectance;
    float refraction;
    float transmittance;
    std::string material;

    const epsilon = 0.1; //intersection threshold

public:
    Sphere(float radius, Vec3f center, RGB_Space rgb, double ka, double kd, double exponent, float reflectance, float transmittance, float refraction, std::string material);
    double Intersect(Ray ray);
};


#endif //RAYTRACER_SPHERE_H
