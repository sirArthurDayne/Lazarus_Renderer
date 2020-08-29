#pragma once
#include "Ray.h"
class Camera{
public:
    Camera();
    Camera(const vec3 pos, float _fov, float _aspect_ratio);
    ~Camera();
    Ray getray(float u, float v);
private:
    vec3 position;
    float fov;
    float aspect_ratio;
};
