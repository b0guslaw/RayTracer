#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "RGB_Space.h"

enum class Light_Type {
    ambient, parallel, point
};

struct Light {
    Light_Type type;
    RGB_Space rgb;

    Light(Light_Type type, RGB_Space rgb) : type{type}, rgb{rgb}{};
};

#endif //RAYTRACER_LIGHT_H
