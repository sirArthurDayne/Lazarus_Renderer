#pragma once
#include "vec.h"

struct Ray {
     Ray();
     Ray(const vec3 ori, const vec3 dir);
     ~Ray();
     vec3 across(float t);

     vec3 origin, direction;
};
