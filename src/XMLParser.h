#ifndef RAYTRACER_XMLPARSER_H
#define RAYTRACER_XMLPARSER_H

#include <iostream>

#include "pugixml.hpp"

#include "Background.h"
#include "Camera.h"
#include "RGB.h"

class XMLParser {
private:
    pugi::xml_document doc;

    pugi::xml_node scene;
    pugi::xml_node background;
    pugi::xml_node camera;
    pugi::xml_node lights;
    pugi::xml_node surfaces;

public:

    XMLParser(const char* path){

            if(!doc.load_file(path)){
                    std::cout << "Could not load file!\n";
            } else {

            }
            scene = doc.child("scene");
            background = scene.child("background_color");
            camera = scene.child("camera");
            lights = scene.child("lights");
            surfaces = scene.child("surfaces");
    }

    Background Parse_Background() {
            RGB rgb(background.attribute("r").as_double(),
                    background.attribute("r").as_double(),
                    background.attribute("r").as_double());

            Background back(rgb);
            return back;
    }
};

#endif //RAYTRACER_XMLPARSER_H
