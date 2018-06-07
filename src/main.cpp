#include <iostream>         //stl imports
#include <string>
#include <fstream>

#include "pugixml.hpp"      //library imports
#include "../lib/glm/glm.hpp"

#include "Background.h"
#include "Camera.h"
#include "XMLParser.h"

void write_ppm(std::string title);
void read_ppm(std::string title); //For debugging purposes

int main(int argc, char** argv) {
    XMLParser parser("../res/example1.xml");
    std::string title = parser.Parse_OutputFile();
    title = "../" + title;

    Background background(parser.Parse_Background());
    Camera camera(parser.Parse_Camera());
    Light light(parser.Parse_Light());
    std::vector<Sphere> sphere_list = parser.Parse_Surface();

    write_ppm(title);
    return 0;
}

void write_ppm(std::string title){
    std::ofstream out;
    out.open(title);

    int width = 600;
    int height = 300;

    out << "P3\n";
    out << width << " " << height << "\n255\n";

    std::cout << "Writing file\n";

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