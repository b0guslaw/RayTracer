#include <iostream>
#include <string>

#include "pugixml.hpp"

#include "Background.h"
#include "Camera.h"
#include "XMLParser.h"

int main(int argc, char** argv) {
    XMLParser parser("../res/example1.xml");
    Background background(parser.Parse_Background());

    background.print_Values();

    /*
    pugi::xml_document doc;
    if(!doc.load_file("../res/example1.xml")){
        std::cout << "Error reading xml\n\n";
        return -1;
    }

    pugi::xml_node scene = doc.child("scene");
    std::cout << scene.name() << "\n\n";

    pugi::xml_node camera = scene.child("camera");

    for(pugi::xml_node node : scene.children()){
        std::cout << node.name() << "\n";
        for(pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute()) {
            std::cout << " " << attr.name() << "=" << attr.value() << "\n";
        }

        for(pugi::xml_attribute attr = node.first_child().first_attribute(); attr; attr = attr.next_attribute()) {
            std::cout << " " << attr.name() << "=" << attr.value() << "\n";
        }

        std::cout << node.first_child().name() << "\n";
        for(pugi::xml_attribute attr = node.first_child().first_child().first_attribute(); attr; attr = attr.next_attribute()) {
            std::cout << " " << attr.name() << "=" << attr.value() << "\n";
        }

      }
       */

    return 0;
}