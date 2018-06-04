#ifndef RAYTRACER_BACKGROUND_H
#define RAYTRACER_BACKGROUND_H

class Background {
private:
    double red;
    double green;
    double blue;
public:
    Background() = delete;
    Background(double red, double green, double blue);
};


#endif //RAYTRACER_BACKGROUND_H
