#ifndef RAYTRACER_XMLPARSER_H
#define RAYTRACER_XMLPARSER_H

#include <iostream>
#include <cstring>

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
                    background.attribute("g").as_double(),
                    background.attribute("b").as_double());

            Background back(rgb);
            return back;
    }

    Camera Parse_Camera() {
        Camera cam(
                camera.child("position").attribute("x").as_double(),
                camera.child("position").attribute("y").as_double(),
                camera.child("position").attribute("z").as_double(),
                camera.child("lookat").attribute("x").as_double(),
                camera.child("lookat").attribute("y").as_double(),
                camera.child("lookat").attribute("z").as_double(),
                camera.child("up").attribute("x").as_double(),
                camera.child("up").attribute("y").as_double(),
                camera.child("up").attribute("z").as_double(),
                camera.child("horizontal_fov").attribute("fov").as_int(),
                camera.child("resolution").attribute("horizontal").as_int(),
                camera.child("resolution").attribute("vertical").as_int(),
                camera.child("max_bounces").attribute("n").as_int()
                );

        return cam;
    }

    void Parse_Light() {
        pugi::xml_node child = lights.child("ambient_light");
        std::cout << child.name() << "\n" << child.first_child().name();
        if(child.name() == "ambient_light") {
            std::cout << "r=" << child.first_child().attribute("r").value()
                    << "g=" << child.first_child().attribute("g").value()
                    << "b=" << child.first_child().attribute("b").value() << "\n";
        }
    }
};

#endif //RAYTRACER_XMLPARSER_H
