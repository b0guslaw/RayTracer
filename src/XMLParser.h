#ifndef RAYTRACER_XMLPARSER_H
#define RAYTRACER_XMLPARSER_H

#include <iostream>
#include <cstring>
#include <vector>

#include "pugixml.hpp"

#include "Background.h"
#include "Camera.h"
#include "RGB_Space.h"
#include "Sphere.h"
#include "Light.h"

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

    std::string Parse_OutputFile(){
        return scene.attribute("output_file").value();
    }

    Background Parse_Background() {
            RGB_Space rgb(background.attribute("r").as_double(),
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

    Light Parse_Light() {
        pugi::xml_node ambient_child = lights.child("ambient_light");
        pugi::xml_node parallel_child = lights.child("parallel_light");
        pugi::xml_node point_child = lights.child("point_light");

        if(ambient_child) {

            RGB_Space rgb(ambient_child.first_child().attribute("r").as_double(),
                    ambient_child.first_child().attribute("g").as_double(),
                    ambient_child.first_child().attribute("b").as_double());

            Light light(Light_Type::ambient, rgb);
            return light;
        }
    }

    std::vector<Sphere> Parse_Surface() {
        std::vector<Sphere> surface_list;
        for(pugi::xml_node child = surfaces; child; child = child.next_sibling()) {
            double radius = child.first_child().attribute("radius").as_double();
            double x, y, z;
            std::string material;
            double ka, kd, exponent, r, t, iof;

            pugi::xml_node subchild = child.first_child().first_child();
            x = subchild.attribute("x").as_double();
            y = subchild.attribute("y").as_double();
            z = subchild.attribute("z").as_double();
            subchild = subchild.next_sibling();
            material = subchild.name();
            subchild = subchild.first_child();
            RGB_Space rgb(
                    subchild.attribute("r").as_double(),
                    subchild.attribute("g").as_double(),
                    subchild.attribute("b").as_double()
                    );
            subchild = subchild.next_sibling();
            ka = subchild.attribute("ka").as_double();
            kd = subchild.attribute("kd").as_double();
            exponent = subchild.attribute("exponent").as_double();
            subchild = subchild.next_sibling();
            r = subchild.attribute("reflectance").as_double();
            subchild = subchild.next_sibling();
            t = subchild.attribute("transmittance").as_double();
            subchild = subchild.next_sibling();
            iof = subchild.attribute("refraction").as_double();

            Sphere sphere(radius, x, y, z, rgb, ka, kd, exponent, r, t, iof, material);
            surface_list.push_back(sphere);
        }

        return surface_list;
    }
};

#endif //RAYTRACER_XMLPARSER_H
