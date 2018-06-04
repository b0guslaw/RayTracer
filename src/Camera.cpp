//
// Created by Ralph on 04.06.2018.
//

#include "Camera.h"

Camera::Camera(double x, double y, double z, double lookat_x, double lookat_y, double lookat_z, int fov,
               int res_horizontal, int res_vertical, int max_bounces) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->lookat_x = lookat_x;
    this->lookat_y = lookat_y;
    this->lookat_z = lookat_z;
    this->fov = fov;
    this->res_horizontal = res_horizontal;
    this->res_vertical = res_vertical;
    this->max_bounces = max_bounces;
}
