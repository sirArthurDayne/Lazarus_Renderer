#include "Ray.h"

Ray::Ray() = default;
Ray::Ray(const vec3 ori, const vec3 dir): origin(ori), direction(dir.normalize()) {}
Ray::~Ray() {}
vec3 Ray::across(float t) { return {origin + direction * t}; }


