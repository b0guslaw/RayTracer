#include <iostream>
#include <string>

#include "pugixml.hpp"
#include "../lib/glm/glm.hpp"

#include "Background.h"
#include "Camera.h"

int main(int argc, char** argv) {
    pugi::xml_document doc;
    if(!doc.load_file("../res/example1.xml")){
        std::cout << "Error reading xml\n\n";
        return -1;
    }

    pugi::xml_node scene = doc.child("scene");
    std::cout << scene.name() << "\n";

    for(pugi::xml_node item = scene.first_child(); item; item = item.next_sibling()) {
        std::cout << item.name() << "\n";

        for(pugi::xml_node child = item.first_child(); child; child = child.next_sibling()) {
            for(pugi::xml_attribute attr = child.first_attribute(); attr; attr = attr.next_attribute()) {
                std::cout << "   " << child.name();
                std::cout << " " << attr.name() << "=" << attr.value() << "\n";
                std::string attrName = attr.name();
            }
        }

        for(pugi::xml_attribute attr = item.first_attribute(); attr; attr = attr.next_attribute()) {
            std::cout << "  " << attr.name() << "=" << attr.value() << "\n";

            std::string attrName = attr.name();
        }

    }
    return 0;
}