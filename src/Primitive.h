#pragma once
#include "Ray.h"

class Primitive
{
    public:
    Primitive();
    virtual ~Primitive();
    virtual float getIntersection(Ray& ray) = 0;
    virtual vec3 getNormal(vec3 collisionPoint) = 0;
};
