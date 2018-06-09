//
// Created by Ralph on 06.06.2018.
//

#include <iostream>
#include "Sphere.h"
#include "Ray.h"
#include "../lib/glm/geometric.hpp"

Sphere::Sphere(float radius, float x, float y, float z,
               RGB_Space rgb, double ka, double kd, double exponent,
               float reflectance, float transmittance, float refraction, std::string material) :
        radius{radius},
        rgb{rgb},
        ka{ka},
        kd{kd},
        exponent{exponent},
        reflectance{reflectance},
        transmittance{transmittance},
        refraction{refraction},
        material{material} {

    Vec3<float> temp(x, y, z);
    center = temp;

    std::cout << temp << std::endl;
}
