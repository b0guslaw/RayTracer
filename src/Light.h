#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "Color.h"

enum class Light_Type {
    ambient, parallel, point
};

struct Light {
    Light_Type type;
    Color rgb;

    Light(Light_Type type, Color rgb) : type{type}, rgb{rgb}{};
};

#endif //RAYTRACER_LIGHT_H
