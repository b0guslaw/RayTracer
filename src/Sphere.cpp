//
// Created by Ralph on 06.06.2018.
//

#include "Sphere.h"

Sphere::Sphere(double radius, double x, double y, double z, RGB rgb, double ka, double ks, double exponent,
               double reflectance, double transmittance, double refraction, std::string material) :
                radius{radius}, x{x}, y{y}, z{z}, rgb{rgb},
                ka{ka}, ks{ks}, exponent{exponent},
                reflectance{reflectance}, transmittance{transmittance}, refraction{refraction}, material{material}{}
