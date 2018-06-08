#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <string>
#include "RGB_Space.h"
#include "../lib/glm/vec3.hpp"
#include "../lib/glm/vec4.hpp"
#include "Ray.h"

class Sphere {
private:
    double radius;
    double x, y , z;
    RGB_Space rgb;
    double ka, kd, ks, exponent;
    double reflectance;
    double refraction;
    double transmittance;
    double iof;
    std::string material;

public:
    Sphere(double radius, double x, double y, double z, RGB_Space rgb,double ka, double kd, double exponent, double reflectance, double transmittance, double refraction, std::string material);

    glm::vec3 center;

    void setRadius(double radius);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setRgb(const RGB_Space &rgb);
    void setKa(double ka);
    void setKd(double kd);
    void setKs(double ks);
    void setExponent(double exponent);
    void setReflectance(double reflectance);
    void setRefraction(double refraction);
    void setTransmittance(double transmittance);
    void setIof(double iof);
    void setMaterial(const std::string &material);

    bool intersect(const Ray &ray);
};


#endif //RAYTRACER_SPHERE_H
