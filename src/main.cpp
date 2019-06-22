#include <iostream>         //stl imports
#include <string>
#include <fstream>
#include <algorithm>
#include <random>
#include <array>

#include "pugixml.hpp"      //library imports

#include "Background.h"
#include "Camera.h"
#include "XMLParser.h"
#include "../lib/OBJ_Loader.h"
#include "Object.h"

Color trace(Ray ray, std::vector<Sphere>&, double&, int &);
void write_ppm(std::string, int, int);
void read_ppm(std::string); //For debugging purposes
std::string print_progress(int);

Background background;
Camera camera;
Light light;
std::vector<Color> image;
std::vector<Light> lights;

const bool RELEASE = false;

int main(int argc, char** argv) {
    int supersample = 20;
    int ss_rate = 1;
    if(argc < 2 && RELEASE){
        std::cout << "ERROR: Please specify where your scene.xml is located\n";
        return -1;
    }

    for(int i = 0; i < argc; i++) {
        if(std::strcmp(argv[i],"--supersample-high") == 0) {
            supersample *= 5;
        }
        if(std::strcmp(argv[i],"--supersample-off") == 0) {
            supersample = 1;
            ss_rate = 0;
        }
    }

    std::cout << "Loading resources\n";
    std::vector<Sphere> sphere_list;
    std::vector<Object> mesh_list;
    std::string title;
    if(RELEASE) {
        XMLParser parser(argv[1]);
        if(!parser.file_loaded()) return -2;
        title = parser.Parse_OutputFile();
        background = parser.Parse_Background();
        camera = parser.Parse_Camera();
        sphere_list = parser.Parse_Surface();
        lights = parser.Parse_Light();
    } else {
        XMLParser parser("../res/example3.xml");
        title = parser.Parse_OutputFile();
        background = parser.Parse_Background();
        camera = parser.Parse_Camera();
        sphere_list = parser.Parse_Surface();
        lights = parser.Parse_Light();
        mesh_list = parser.Parse_Mesh();
    }

    for(auto o : mesh_list) {
        o.pretty_print();
    }

    std::cout << "Generating image\n";
    std::random_device rd;
    std::mt19937_64 rng(rd());
    std::uniform_real_distribution<> dis(0,ss_rate);

    for(int j = 0; j < camera.res_vertical; j++) {
        std::cout << print_progress((double)j/camera.res_vertical * 10);
        for(int i = 0; i < camera.res_horizontal; i++) {
            Color avg = Vec3<float> (0,0,0);
            Color color;
            for(int s = 0; s < supersample; s++) {
                Ray ray = camera.constructRay(i + dis(rng), j + dis(rng));
                double traversal;
                int hit;
                color = trace(ray, sphere_list, traversal, hit);

                if(hit >= 0) {
                    Vec3f WorldPosition = ray.origin + ray.direction * Vec3f(traversal);
                    Vec3f WorldToSphereVector = (WorldPosition - sphere_list[hit].getCenter()).Unit();
                    Vec3f TotalLightFactor = Vec3f(0.);

                    for(auto &light : lights) {
                        switch(light.type) {
                            case Light_Type::ambient:
                                TotalLightFactor += light.rgb.getRgb();
                                break;
                            case Light_Type::parallel:
                                TotalLightFactor += Vec3f(std::max(WorldToSphereVector.dot(light.pos.Unit()),0.f)) * light.rgb.getRgb();
                                Vec3f ReflectionVector = ray.direction - Vec3f(2. * ray.direction.dot(WorldToSphereVector)) * WorldToSphereVector;
                                TotalLightFactor += Vec3f(std::pow(std::max(ReflectionVector.dot(light.pos.Unit()),0.f),100.)) * light.rgb.getRgb();
                                break;

                        }
                    }

                    avg += (Color(color.rgb * TotalLightFactor));
                } else {
                    avg += color;
                }
            }
            avg.rgb = avg.rgb / supersample;
            image.push_back(avg);
            /*
            Ray ray = camera.constructRay(i,j);
            double traversal;
            int hit;
            Color color = trace(ray, sphere_list, traversal, hit);

            if(hit >= 0) {
                Vec3f WorldPosition = ray.origin + ray.direction * Vec3f(traversal);
                Vec3f WorldToSphereVector = (WorldPosition - sphere_list[hit].getCenter()).Unit();
                Vec3f TotalLightFactor = Vec3f(0.);

                for(auto &light : lights) {
                    switch(light.type) {
                        case Light_Type::ambient:
                            TotalLightFactor += light.rgb.getRgb();
                            break;
                        case Light_Type::parallel:
                            TotalLightFactor += Vec3f(std::max(WorldToSphereVector.dot(light.pos.Unit()),0.f)) * light.rgb.getRgb();
                            Vec3f ReflectionVector = ray.direction - Vec3f(2. * ray.direction.dot(WorldToSphereVector)) * WorldToSphereVector;
                            TotalLightFactor += Vec3f(std::pow(std::max(ReflectionVector.dot(light.pos.Unit()),0.f),100.)) * light.rgb.getRgb();
                            break;

                    }
                }
                image.push_back(Color(color.rgb * TotalLightFactor));

            }
            else
            image.push_back(color);
             */
        }
    }

    write_ppm(title, camera.res_vertical, camera.res_horizontal);
    std::cout << "Done\n";
    return 0;
}

Color trace(Ray ray, std::vector<Sphere> &objectList, double &traversal, int &hit){
    traversal = -1.0;
    double minDepth = -1.0;
    int obj = -1;

    for(int currentObject = 0; currentObject < objectList.size(); currentObject++) {
        double depth = objectList[currentObject].Intersect(ray);
        obj  = ((minDepth  < 0. || depth < minDepth) && depth > 0.) ? currentObject : obj;
        minDepth = ((minDepth  < 0. || depth < minDepth) && depth > 0.) ? depth : minDepth;
        traversal  = minDepth;
    }
    hit = obj;
    return traversal > 0. ? objectList[obj].getColor() : background.color;
}

void write_ppm(std::string title, int width, int height){
    std::ofstream out;
    out.open(title);

    out << "P3\n";
    out << width << " " << height << "\n255\n";

    std::cout << "\nWriting file\n";

    for(int j = 0; j < height*width; j++) {
        if(j % width == 0) {
            out << "\n";
        }

        //https://stackoverflow.com/questions/1914115/converting-color-value-from-float-0-1-to-byte-0-255
        int r = (image[j].rgb.getX() >= 1.0 ? 255 : (image[j].rgb.getX() <= 0.0 ? 0 : (int)floor(image[j].rgb.getX() * 256.0)));
        int g = (image[j].rgb.getY() >= 1.0 ? 255 : (image[j].rgb.getY() <= 0.0 ? 0 : (int)floor(image[j].rgb.getY() * 256.0)));
        int b = (image[j].rgb.getZ() >= 1.0 ? 255 : (image[j].rgb.getZ() <= 0.0 ? 0 : (int)floor(image[j].rgb.getZ() * 256.0)));

        out << r << " " << g << " " << b <<" ";
    }

    out << "\n";
    out.close();
}

//Debug function
void read_ppm(std::string title){
    std::ifstream in;
    std::string line;
    in.open(title);

    while(std::getline(in, line)){
        std::cout << line << "\n";
    }
}

std::string print_progress(int prog) {
    std::string s = "\r[";
    for(int i = 0; i != 10; i++) {
        if(i <= prog) s+= "#";
        if(i > prog) s+= "-";
    }
    s += "]";
    return s;
}

