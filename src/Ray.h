#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vec3.h"

typedef Vec3<float> Vec3f;

struct Ray {
    Vec3f origin;
    Vec3f direction;
    float time;
};

#endif //RAYTRACER_RAY_H
