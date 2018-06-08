//
// Created by Ralph on 04.06.2018.
//

#include <iostream>
#include "Camera.h"

Camera::Camera(double x, double y, double z, double lookat_x, double lookat_y, double lookat_z, double up_x, double up_y,
               double upz, int fov, int res_horizontal, int res_vertical, int max_bounces) :
                x{x}, y{y}, z{z},
                lookat_x{lookat_x}, lookat_y{lookat_y}, lookat_z{lookat_z},
                up_x{up_x}, up_y{up_y}, up_z{up_z},
                fov{fov}, res_horizontal{res_horizontal}, res_vertical{res_vertical},
                max_bounces{max_bounces} {
    position = glm::vec3(x,y,z);
    lookat = glm::vec3(lookat_x, lookat_y, lookat_z);
    up = glm::vec3(up_x, up_y, up_z);

    glm::vec3 Z = position - lookat / glm::abs(position - lookat);
    glm::vec3 X = glm::cross(up, Z) / glm::abs(glm::cross(up, Z));
    glm::vec3 Y = glm::cross(Z,X) / glm::abs(glm::cross(Z,X));

    glm::vec4 X_ = glm::vec4(X.x, X.y, X.z, 0.0);
    glm::vec4 Y_ = glm::vec4(Y.x, Y.y, Y.z, 0.0);
    glm::vec4 Z_ = glm::vec4(Z.x, Z.y, Z.z, 0.0);
    glm::vec4 Pos = glm::vec4(x, y, z, 1.0);

    camera_matrix = glm::mat4(X_, Y_, Z_, Pos);

}
