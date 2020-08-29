#include "Camera.h"

Camera::Camera() {}
Camera::Camera(const vec3 pos, float _fov,float _aspect_ratio): position(pos),
    fov(_fov), aspect_ratio(_aspect_ratio) {}
Camera::~Camera() {}
Ray Camera::getray(float u, float v)
{
    const float fov_rad = fov/180.0f;
    const float x = (u * 2.0f -1.0f) * fov_rad;
    const float y = (v * 2.0f -1.0f) * fov_rad * aspect_ratio;
    const float z = 1.0f;
    return {position, vec3(x,y,z).normalize()};
}
