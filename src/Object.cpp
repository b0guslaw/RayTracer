//
// Created by ralph on 21.06.2019.
//

#include "Object.h"

Object::Object(std::vector<std::array<double,3>> in) {
    for(auto p : in) {
        vert.push_back(Vec3f(p[0],p[1],p[2]));
    }
}

void Object::pretty_print() {
    std::cout << "Object start:\nDefining Vertices:\n";
    for(auto face : vert) {
        std::cout << face << "\n";
    }
    std::cout << "Color values:\n" << color;
    std::cout << "\nPhong values:\nka: " << ka << "\nkd: " << kd << "\nks: " << ks << "\nexp: " << exponent;
    std::cout << "\nReflectance: " << reflectance << "\nTransmittance " << transmittance;
    std::cout << "\nRefraction: " << iof << "\n";
}

double Object::intersect(Ray, int idx) {

}
