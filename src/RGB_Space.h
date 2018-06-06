#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

struct RGB_Space {
    double r;
    double g;
    double b;

    RGB_Space();
    RGB_Space(double r, double b, double g) : r{r}, g{g}, b{b} {

    }
};

#endif //RAYTRACER_RGB_H
