#ifndef RAYTRACER_BACKGROUND_H
#define RAYTRACER_BACKGROUND_H

#include "Color.h"

struct Background {
    Color color;
    Background() { color = Vec3f(0); }
    Background(Color color) : color{color} {}
    Background(const Background& c) : color{c.color} {}
};


#endif //RAYTRACER_BACKGROUND_H
