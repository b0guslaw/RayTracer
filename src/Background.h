#ifndef RAYTRACER_BACKGROUND_H
#define RAYTRACER_BACKGROUND_H

#include <iostream>
#include "RGB.h"

class Background {
private:
    RGB color;
public:
    Background(RGB _color);

    void print_Values(){
        std::cout << "r=" << color.r
                  << "\ng=" << color.g
                  << "\nr=" << color.b << "\n\n";
     }
};


#endif //RAYTRACER_BACKGROUND_H
