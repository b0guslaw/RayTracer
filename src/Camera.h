#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "../lib/glm/vec3.hpp"
#include "../lib/glm/geometric.hpp"
#include "../lib/glm/detail/type_mat.hpp"*
#include "../lib/glm/detail/type_mat4x4.hpp"

class Camera {
private:
    double x, y, z; //position of camera
    double lookat_x, lookat_y, lookat_z;
    double up_x, up_y, up_z;
    int fov;
    int max_bounces;
public:
    Camera() = delete;
    Camera(double x, double y, double z,
           double lookat_x,double lookat_y, double lookat_z,
           double up_x, double up_y, double up_z,
           int fov,
           int res_horizontal, int res_vertical,
           int max_bounces);

    int res_horizontal, res_vertical;
    glm::vec3 position;
    glm::vec3 lookat;
    glm::vec3 up;
    glm::mat4 camera_matrix;
};


#endif //RAYTRACER_CAMERA_H
