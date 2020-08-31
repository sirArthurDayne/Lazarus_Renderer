#include "Sphere.h"
#include <corecrt_math.h>

Sphere::Sphere() {}
Sphere::Sphere(vec3 c, float _radius): center(c), radius(_radius)  {}
Sphere::~Sphere() {}

float Sphere::getIntersection(Ray& ray)
{
    vec3 origin = ray.origin;
    vec3 oc = origin - center;
    float b = 2.0f *oc.dot(ray.direction);
    float c = oc.dot(oc) - radius * radius;
    const float discr = b*b - 4.0f * c;
    if (discr < 0.0f)
        return -1.0f;
    const float sq_discr = sqrtf(discr);
    float dist1 = -b - sq_discr;
    float dist2 = -b + sq_discr;
    return (dist1 > 0.0f) ? dist1/2.f : (dist2 > 0.0f) ? dist2/2.f : -1.0f;
}

vec3 Sphere::getNormal(vec3 collisionPoint)
{
    return ((collisionPoint-center)/radius).normalize();
}
