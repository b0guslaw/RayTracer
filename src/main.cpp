#include <iostream>         //stl imports
#include <string>
#include <fstream>

#include "pugixml.hpp"      //library imports
#include "../lib/glm/glm.hpp"

#include "Background.h"
#include "Camera.h"
#include "XMLParser.h"

Color trace(Ray ray, std::vector<Sphere>&, bool&);
void write_ppm(std::string, int, int);
void read_ppm(std::string); //For debugging purposes

Background background;
Camera camera;
Light light;
std::vector<Color> image;


int main(int argc, char** argv) {
    XMLParser parser("../res/example1.xml");
    std::string title = parser.Parse_OutputFile();
    title = "../" + title;

    background = parser.Parse_Background();
    camera = parser.Parse_Camera();
    light = parser.Parse_Light();
    std::vector<Sphere> sphere_list = parser.Parse_Surface();

    for(int j = 0; j < camera.res_vertical; j++) {
        for(int i = 0; i < camera.res_horizontal; i++) {
            Ray ray = camera.constructRay(i,j);
            bool intersection;
            Color color = trace(ray, sphere_list, intersection);
            image.push_back(color);
        }
    }


    write_ppm(title, camera.res_vertical, camera.res_horizontal);
    return 0;
}

Color trace(Ray ray, std::vector<Sphere> &objectList, bool &intersection){
    intersection = false;
    double minDepth = -1.0;
    int obj = -1;

    for(int currentObject = 0; currentObject < objectList.size(); currentObject++) {
        double depth = objectList[currentObject].Intersect(ray);
        obj  = ((minDepth  < 0. || depth < minDepth) && depth > 0.) ? currentObject : obj;
        minDepth = ((minDepth  < 0. || depth < minDepth) && depth > 0.) ? depth : minDepth;
        intersection  = minDepth  > 0.;

    }

    //std::cout << minDepth << '\n';

    return intersection ? objectList[obj].getColor() : background.color;
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
             //r         //g         //b
        int r = (image[j].rgb.getX() >= 1.0 ? 255 : (image[j].rgb.getX() <= 0.0 ? 0 : (int)floor(image[j].rgb.getX() * 256.0)));
        int g = (image[j].rgb.getY() >= 1.0 ? 255 : (image[j].rgb.getY() <= 0.0 ? 0 : (int)floor(image[j].rgb.getY() * 256.0)));
        int b = (image[j].rgb.getZ() >= 1.0 ? 255 : (image[j].rgb.getZ() <= 0.0 ? 0 : (int)floor(image[j].rgb.getZ() * 256.0)));

        out << r << " " << g << " " << b <<" ";

    }

    out << "\n";
    out.close();
}

void read_ppm(std::string title){
    std::ifstream in;
    std::string line;
    in.open(title);

    while(std::getline(in, line)){
        std::cout << line << "\n";
    }
}

