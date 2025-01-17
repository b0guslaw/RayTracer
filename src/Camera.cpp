#include "Camera.h"

Camera::Camera() {}

Camera::Camera(Vec3f position, Vec3f lookAt, Vec3f up,
               double fov, int res_horizontal, int res_vertical, int n)  :
                position{position}, lookAt{lookAt} , up{up}, fov{fov}, //0.785398
                res_horizontal{res_horizontal}, res_vertical{res_vertical}, n{n}{

    Vec3f LookAt_Position = position - lookAt;
    //Z_Viewing = LookAt_Position.Unit();
    //X_Viewing = up.cross(Z_Viewing).Unit();
    //Y_Viewing = Z_Viewing.cross(X_Viewing).Unit();

    auto fov_rad = static_cast<float>(fov);
    fov_rad = fov_rad * (180.0f / static_cast<float>(M_PI));

    width = static_cast<float>(tan(fov_rad));
    height = static_cast<float>(tan(fov_rad)*res_vertical/res_horizontal);

    wRes_x = width / res_horizontal;
    hRes_y = height/ res_vertical;
    widthHalf = width / 2;
    heightHalf = height / 2;
}

Ray Camera::constructRay(const double &u, const double &v) {
    auto x = static_cast<float>(wRes_x * (u + 0.5) - widthHalf);
    auto y = static_cast<float>(-1 * (hRes_y) * (v + 0.5) + heightHalf);

    float z = -1.0;
    Ray ray;
    ray.origin = position;  //ray origin resides at camera position
    Vec3f pixel{x,y,z};
    ray.direction = pixel.Unit();
    return ray;
}

void Camera::set_time(float t0, float t1) {
    time0 = t0;
    time1 = t1;
}




