#ifndef RAYTRACER_XMLPARSER_H
#define RAYTRACER_XMLPARSER_H

#include "pugixml.hpp"

class XMLParser {
private:
    pugi::xml_document doc;
public:

    XMLParser(const char* path){
        doc.load_file(path);
    }

};

#endif //RAYTRACER_XMLPARSER_H
