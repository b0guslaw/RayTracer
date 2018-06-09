#ifndef RAYTRACER_BACKGROUND_H
#define RAYTRACER_BACKGROUND_H

#include <iostream>
#include "Color.h"

struct Background {
private:
    Color color;
public:
    Background(Color _color) : color{_color} {};
};


#endif //RAYTRACER_BACKGROUND_H
