#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "Color.h"

enum class Light_Type {
    ambient, parallel, point
};

struct Light {
    Light_Type type;
    Color rgb;
    Vec3f pos;

    Light() {};
    Light(Light_Type type, Color rgb, Vec3f pos) : type{type}, rgb{rgb}, pos{pos}{};
    Light(const Light& l) : type{l.type} , rgb{l.rgb}, pos{l.pos} {};
};

#endif //RAYTRACER_LIGHT_H
