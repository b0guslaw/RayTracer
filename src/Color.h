#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

#include "Vec3.h"

typedef Vec3<float> Vec3f;

struct Color {
    Vec3f rgb;

    const Vec3f &getRgb() const {
        return rgb;
    }

    Color() {
        rgb;
    }
    Color(const Vec3f &rgb) : rgb(rgb) {}
};

#endif //RAYTRACER_RGB_H
