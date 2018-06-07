//
// Created by Ralph on 04.06.2018.
//

#include "Camera.h"

Camera::Camera(double x, double y, double z, double lookat_x, double lookat_y, double lookat_z, double up_x, double up_y,
               double upz, int fov, int res_horizontal, int res_vertical, int max_bounces) :
                x{x}, y{y}, z{z},
                lookat_x{lookat_x}, lookat_y{lookat_y}, lookat_z{lookat_z},
                up_x{up_x}, up_y{up_y}, up_z{upz},
                fov{fov}, res_horizontal{res_horizontal}, res_vertical{res_vertical},
                max_bounces{max_bounces} {
    position = glm::vec3(x,y,z);
}
