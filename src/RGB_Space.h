#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

struct RGB_Space {
    float r;
    float g;
    float b;

    RGB_Space();
    RGB_Space(float r, float b, float g) : r{r}, g{g}, b{b} {

    }
};

#endif //RAYTRACER_RGB_H
