#include "Camera.h"

Camera::Camera() {}

Camera::Camera(Vec3f position, Vec3f lookAt, Vec3f up,
               double fov, int res_horizontal, int res_vertical, int n)  :
                position{position}, lookAt{lookAt} , up{up}, fov{fov},
                res_horizontal{res_horizontal}, res_vertical{res_vertical}, n{n}{

    Vec3f LookAt_Position = position - lookAt;
    Z_Viewing = LookAt_Position.Unit();
    Y_Viewing = up.Unit();
    Vec3f Cross_Up_Z = up.cross(Z_Viewing);
    X_Viewing = Cross_Up_Z.Unit();

    width = static_cast<float>(tan(fov/2));
    height = static_cast<float>(tan((fov/2)*res_vertical/res_horizontal));

    wRes_x = width / res_horizontal;
    hRes_y = height/ res_vertical;
    widthHalf = width / 2;
    heightHalf = height / 2;
}

Ray Camera::constructRay(const int &u, const int &v) {
    auto x = static_cast<float>(wRes_x * (u + 0.5) - widthHalf);
    auto y = static_cast<float>(-1 * (hRes_y) * (v + 0.5) + heightHalf);

    float z = -1;
    Ray ray;
    ray.origin = position;  //ray origin resides at camera position
    Vec3f pixel{x,y,z};
    ray.direction = pixel.Unit();
    return ray;
}




