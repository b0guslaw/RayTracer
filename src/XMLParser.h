#ifndef RAYTRACER_XMLPARSER_H
#define RAYTRACER_XMLPARSER_H

#include <iostream>
#include <cstring>
#include <vector>

#include "pugixml.hpp"

#include "Background.h"
#include "Camera.h"
#include "Color.h"
#include "Sphere.h"
#include "Light.h"
#include "Vec3.h"
#include "Object.h"
#include "../lib/OBJ_Loader.h"

typedef Vec3<float> Vec3f;

/**
 * Main XML Parsing class
 */
class XMLParser {
private:
    pugi::xml_document doc;
    pugi::xml_node scene;
    pugi::xml_node background;
    pugi::xml_node camera;
    pugi::xml_node lights;
    pugi::xml_node surfaces;
    bool success = false;

public:

    XMLParser(const char* path){
            if(!doc.load_file(path)){
                    std::cout << "Could not load file!\n";
            }
            scene = doc.child("scene");
            background = scene.child("background_color");
            camera = scene.child("camera");
            lights = scene.child("lights");
            surfaces = scene.child("surfaces");
            success = true;
    }

    std::string Parse_OutputFile(){
        std::string file_name = scene.attribute("output_file").value();
        file_name = file_name.substr(0, file_name.find(".",0));
        return file_name + ".ppm";
    }

    Background Parse_Background() {
            Vec3f rgb(background.attribute("r").as_float(),
                    background.attribute("g").as_float(),
                    background.attribute("b").as_float());

            Background back(rgb);
            return back;
    }

    Camera Parse_Camera() {
        Camera cam(
                Vec3f(camera.child("position").attribute("x").as_float(),
                      camera.child("position").attribute("y").as_float(),
                      camera.child("position").attribute("z").as_float()),

                Vec3f( camera.child("lookat").attribute("x").as_float(),
                       camera.child("lookat").attribute("y").as_float(),
                       camera.child("lookat").attribute("z").as_float()),

                Vec3f(camera.child("up").attribute("x").as_float(),
                      camera.child("up").attribute("y").as_float(),
                      camera.child("up").attribute("z").as_float()),

                camera.child("horizontal_fov").attribute("angle").as_int(),
                camera.child("resolution").attribute("horizontal").as_int(),
                camera.child("resolution").attribute("vertical").as_int(),
                camera.child("max_bounces").attribute("n").as_int()
                );
        return cam;
    }

    //TODO point light parsing
    std::vector<Light> Parse_Light() {
        std::vector<Light> light_list;
        pugi::xml_node ambient_child = lights.child("ambient_light");
        pugi::xml_node parallel_child = lights.child("parallel_light");
        pugi::xml_node point_child = lights.child("point_light");

        if(ambient_child) {
            Vec3f rgb(ambient_child.first_child().attribute("r").as_float(),
                    ambient_child.first_child().attribute("g").as_float(),
                    ambient_child.first_child().attribute("b").as_float());

            Light a_light(Light_Type::ambient, rgb, Vec3f{0});
            light_list.push_back(a_light);
        }

        if(parallel_child) {
            Vec3f rgb(parallel_child.first_child().attribute("r").as_float(),
                      parallel_child.first_child().attribute("g").as_float(),
                      parallel_child.first_child().attribute("b").as_float());

            Vec3f pos(parallel_child.first_child().next_sibling().attribute("x").as_float(),
                      parallel_child.first_child().next_sibling().attribute("y").as_float(),
                      parallel_child.first_child().next_sibling().attribute("z").as_float()
            );

            Light p_light(Light_Type::parallel, rgb, pos);
            light_list.push_back(p_light);

        }
        return light_list;
    }

    std::vector<Sphere> Parse_Surface() {
        std::vector<Sphere> surface_list;
        for(pugi::xml_node child = surfaces.first_child(); child; child = child.next_sibling()) {
            float radius = child.attribute("radius").as_float();
            float x, y, z;
            std::string material;
            double ka, kd, exponent;
            float r, t, iof;

            pugi::xml_node subchild = child.first_child();
            x = subchild.attribute("x").as_float();
            y = subchild.attribute("y").as_float();
            z = subchild.attribute("z").as_float();

            subchild = subchild.next_sibling();
            material = subchild.name();
            subchild = subchild.first_child();
            Vec3f rgb(
                    subchild.attribute("r").as_float(),
                    subchild.attribute("g").as_float(),
                    subchild.attribute("b").as_float()
                    );
            subchild = subchild.next_sibling();
            ka = subchild.attribute("ka").as_double();
            kd = subchild.attribute("kd").as_double();
            exponent = subchild.attribute("exponent").as_double();
            subchild = subchild.next_sibling();
            r = subchild.attribute("reflectance").as_float();
            subchild = subchild.next_sibling();
            t = subchild.attribute("transmittance").as_float();
            subchild = subchild.next_sibling();
            iof = subchild.attribute("refraction").as_float();

            Sphere sphere(radius, Vec3f(x,y,z), rgb, ka, kd, exponent, r, t, iof, material);
            surface_list.push_back(sphere);
        }
        return surface_list;
    }

    std::vector<Object> Parse_Mesh() {
        std::vector<Object> mesh_list;
        objl::Loader loader;

        for(pugi::xml_node child = surfaces.first_child(); child; child = child.next_sibling()) {
            std::string path = child.attribute("name").as_string();
            loader.LoadFile("../res/"+path);
            std::vector<std::array<double,3>> data;
            for(int i = 0; i < loader.LoadedMeshes.size(); i++) {
                objl::Mesh mesh = loader.LoadedMeshes[i];
                for(int j = 0; j < mesh.Vertices.size(); j++) {
                    std::array<double,3> t{mesh.Vertices[j].Position.X,mesh.Vertices[j].Position.Y,mesh.Vertices[j].Position.Z};
                    data.push_back(t);
                }
                Object o(data);
                pugi::xml_node subchild = child.first_child();
                subchild = subchild.first_child();
                o.color = Vec3f(subchild.attribute("r").as_float(),subchild.attribute("g").as_float(),subchild.attribute("b").as_float());
                subchild = subchild.next_sibling();
                o.ka = subchild.attribute("ka").as_double();
                o.kd = subchild.attribute("kd").as_double();
                o.ks = subchild.attribute("ks").as_double();
                o.exponent = subchild.attribute("exponent").as_double();
                subchild = subchild.next_sibling();
                o.reflectance = subchild.attribute("r").as_float();
                subchild = subchild.next_sibling();
                o.transmittance = subchild.attribute("t").as_float();
                subchild = subchild.next_sibling();
                o.iof = subchild.attribute("iof").as_float();
                mesh_list.push_back(o);
            }

        }
        return mesh_list;
    }

    bool file_loaded() { return success; }
};

#endif //RAYTRACER_XMLPARSER_H
