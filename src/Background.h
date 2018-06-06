#ifndef RAYTRACER_BACKGROUND_H
#define RAYTRACER_BACKGROUND_H

#include <iostream>
#include "RGB_Space.h"

class Background {
private:
    RGB_Space color;
public:
    Background(RGB_Space _color);

    void print_Values(){
        std::cout << "r=" << color.r
                  << "\ng=" << color.g
                  << "\nr=" << color.b << "\n\n";
     }
};


#endif //RAYTRACER_BACKGROUND_H
