//
// Created by Ralph on 06.06.2018.
//

#include "Sphere.h"
#include "Ray.h"
#include "../lib/glm/geometric.hpp"

Sphere::Sphere(double radius, double x, double y, double z, RGB_Space rgb, double ka, double ks, double exponent,
               double reflectance, double transmittance, double refraction, std::string material) :
                radius{radius}, x{x}, y{y}, z{z}, rgb{rgb},
                ka{ka}, kd{kd}, exponent{exponent},
                reflectance{reflectance}, transmittance{transmittance}, refraction{refraction}, material{material}{
    center = glm::vec3(x,y,z);
}


void Sphere::setRadius(double radius) {
    Sphere::radius = radius;
}

void Sphere::setX(double x) {
    Sphere::x = x;
}

void Sphere::setY(double y) {
    Sphere::y = y;
}

void Sphere::setZ(double z) {
    Sphere::z = z;
}

void Sphere::setRgb(const RGB_Space &rgb) {
    Sphere::rgb = rgb;
}

void Sphere::setKa(double ka) {
    Sphere::ka = ka;
}

void Sphere::setKd(double kd) {
    Sphere::kd = kd;
}

void Sphere::setKs(double ks) {
    Sphere::ks = ks;
}

void Sphere::setExponent(double exponent) {
    Sphere::exponent = exponent;
}

void Sphere::setReflectance(double reflectance) {
    Sphere::reflectance = reflectance;
}

void Sphere::setRefraction(double refraction) {
    Sphere::refraction = refraction;
}

void Sphere::setTransmittance(double transmittance) {
    Sphere::transmittance = transmittance;
}

void Sphere::setIof(double iof) {
    Sphere::iof = iof;
}

void Sphere::setMaterial(const std::string &material) {
    Sphere::material = material;
}

bool Sphere::intersect(const Ray& ray) {
    glm::vec3 l = center - ray.origin;

}