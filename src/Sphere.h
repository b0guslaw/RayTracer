#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <string>

#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

typedef Vec3<float> Vec3f;

class Sphere {
private:
    Vec3f center;
    float radius;
    Color rgb;
    double ka, kd, ks, exponent;
    float reflectance;
    float refraction;
    float transmittance;
    std::string material;

    const float epsilon = 0.1; //intersection threshold

public:
    Sphere(float radius, Vec3f center, Color rgb, double ka, double kd, double exponent, float reflectance, float transmittance, float refraction, std::string material);
    double Intersect(Ray ray);
    Color getColor();
};


#endif //RAYTRACER_SPHERE_H
