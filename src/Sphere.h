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
public:
    const Vec3f &getCenter() const;

private:
    float radius;
    Color rgb;
    double ka, kd, exponent;
    float reflectance;
    float refraction;
    float transmittance;
    std::string material;

    float time0, time1;
    Vec3f center0, center1;

    const float epsilon = 0.1; //intersection threshold, hardcoded

public:
    Sphere(float radius, Vec3f center, Color rgb, double ka, double kd, double exponent, float reflectance, float transmittance, float refraction, std::string material);
    double Intersect(Ray ray);
    Color getColor();
    void set_time(float, float);
};


#endif //RAYTRACER_SPHERE_H
