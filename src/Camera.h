#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

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
};


#endif //RAYTRACER_CAMERA_H
