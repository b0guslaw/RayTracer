#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include <vector>
#include <iostream>

#include "Vec3.h"
#include "Ray.h"

typedef Vec3<float> Vec3f;

class Camera {
private:
    Vec3f position; //position of camera
    Vec3f lookAt;
    Vec3f up;
    int fov;
    int n; //max bounces

    float widthHalf;
    float heightHalf;
    float wRes_x;
    float hRes_y;
public:
    int res_horizontal, res_vertical;
    Vec3f X_Viewing, Y_Viewing, Z_Viewing;
    float width, height;
    Ray constructRay(const int &u, const int &v);
    Camera();
    Camera(Vec3f position,
           Vec3f lookAt,
           Vec3f up,
           int fov,
           int res_horizontal, int res_vertical,
           int n);

};


#endif //RAYTRACER_CAMERA_H
