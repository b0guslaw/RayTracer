#ifndef RAYTRACER_RGB_H
#define RAYTRACER_RGB_H

struct RGB {
    double r;
    double g;
    double b;

    RGB(double _r, double _g, double _b) : r{_r} , g{_g}, b{_b} {}
};
#endif //RAYTRACER_RGB_H
