#include "Camera.h"

Camera::Camera() {}

Camera::Camera(Vec3f position, Vec3f lookAt, Vec3f up,
               int fov, int res_horizontal, int res_vertical, int n)  :
                position{position}, lookAt{lookAt} , up{up}, fov{fov},
                res_horizontal{res_horizontal}, res_vertical{res_vertical}, n{n}{

    Vec3f LookAt_Position = position - lookAt;
    Z_Viewing = LookAt_Position.Unit();
    Y_Viewing = up.Unit();
    Vec3f Cross_Up_Z = up.cross(Z_Viewing);
    X_Viewing = Cross_Up_Z.Unit();

    width = static_cast<float>(tan(0.5));
    height = static_cast<float>(tan((0.5)*res_vertical/res_horizontal));

    wRes_x = width / res_horizontal;
    hRes_y = height/ res_vertical;
    widthHalf = width / 2;
    heightHalf = height / 2;
}

Ray Camera::constructRay(const int &u, const int &v) {
    float u_w = static_cast<float>(u)/res_vertical;
    float v_w = static_cast<float>(v)/res_horizontal;
    auto x = static_cast<float>(wRes_x * (u + 0.5) - widthHalf);
    auto y = static_cast<float>(-1 * (hRes_y) * (v + 0.5) + heightHalf);



    float z = -1;
    Ray ray;
    ray.origin = position;
    Vec3f pixel{x,y,z};
    //Vec3f hard{0,0,-1};
    ray.direction = pixel.Unit();
    //std::cout << pixel << " <=> " << ray.direction << std::endl;
    return ray;
}




