#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "../lib/glm/vec4.hpp"
#include "../lib/glm/vec3.hpp"

struct Ray {
    glm::vec3 origin;
    glm::vec3 direction;
};

#endif //RAYTRACER_RAY_H
