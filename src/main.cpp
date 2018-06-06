#include <iostream>         //stl imports
#include <string>

#include "pugixml.hpp"      //library imports
#include "../lib/glm/glm.hpp"

#include "Background.h"
#include "Camera.h"
#include "XMLParser.h"

int main(int argc, char** argv) {
    XMLParser parser("../res/example1.xml");
    Background background(parser.Parse_Background());
    Camera camera(parser.Parse_Camera());
    Light light(parser.Parse_Light());
    std::vector<Sphere> sphere_list = parser.Parse_Surface();

    return 0;
}