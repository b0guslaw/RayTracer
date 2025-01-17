#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include <vector>
#include <iostream>

#include "Vec3.h"
#include "Ray.h"

typedef Vec3<float> Vec3f;

/**
 * In this class hold all our important values for our camera, and also provide a
 * fucntion for constructing eye rays
 */
class Camera {
private:
    Vec3f position; //position of camera
    Vec3f lookAt;
    Vec3f up;
    double fov;
    int n; //max bounces

    float widthHalf;
    float heightHalf;
    float wRes_x;
    float hRes_y;
    float time0, time1;
public:
    int res_horizontal, res_vertical;
    Vec3f X_Viewing, Y_Viewing, Z_Viewing;
    float width, height;
    Ray constructRay(const double &u, const double &v);
    Camera();
    Camera(Vec3f position,
           Vec3f lookAt,
           Vec3f up,
           double fov,
           int res_horizontal, int res_vertical,
           int n);
    void set_time(float,float);
};


#endif //RAYTRACER_CAMERA_H
