#include <iostream>         //stl imports
#include <string>
#include <fstream>


#include "pugixml.hpp"      //library imports
#include "../lib/glm/glm.hpp"

#include "Background.h"
#include "Camera.h"
#include "XMLParser.h"

Color trace(Ray ray, std::vector<Sphere>&);
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

    std::cout << background.color.rgb << std::endl;

    for(int j = 0; j < camera.res_vertical; j++) {
        for(int i = 0; i < camera.res_horizontal; i++) {
            Ray ray = camera.constructRay(i,j);
            Color color = trace(ray, sphere_list);

            image.push_back(color);
        }
    }


    write_ppm(title, camera.res_vertical, camera.res_horizontal);
    return 0;
}

Color trace(Ray ray, std::vector<Sphere> &objectList){
    bool intersection = false;
    double minDepth = -1.0;
    int obj = -1;

    for(auto object : objectList) {
        double depth = object.Intersect(ray);
        if(depth == -1){
            return background.color;
        } else {
            return object.getColor();
        }
    }
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
        out << 0 << " " << 0 << " " << 0 <<" ";

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

