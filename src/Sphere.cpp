//
// Created by Ralph on 06.06.2018.
//

#include <iostream>
#include "Sphere.h"
#include "Ray.h"
#include "../lib/glm/geometric.hpp"

Sphere::Sphere(float radius, Vec3f center,
               Color rgb, double ka, double kd, double exponent,
               float reflectance, float transmittance, float refraction, std::string material) :
        radius{radius},
        center{center},
        rgb{rgb},
        ka{ka},
        kd{kd},
        exponent{exponent},
        reflectance{reflectance},
        transmittance{transmittance},
        refraction{refraction},
        material{material} {
    std::cout << "rgb = " << rgb.rgb << "\n";
}

double Sphere::Intersect(Ray ray) {
    Vec3f Sphere_Ray_Vector = center - ray.origin;
    double B = Sphere_Ray_Vector.dot(ray.direction);
    //Discriminant of quadratic solution
    double Det = B * B - Sphere_Ray_Vector.dot(Sphere_Ray_Vector) + (radius * radius);

    if(Det < .0) {
        return -1; //No point will be hit
    } else {
        Det = sqrt(Det);
    }

    //Solving quadratic solution
    if(B - Det > epsilon){
        return B - Det;
    } else if (B + Det > epsilon) {
        return B + Det;
    }
    return -1;
}
