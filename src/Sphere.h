#pragma once
#include "vec.h"
#include "Primitive.h"

class Sphere : public Primitive{
public:
    Sphere();
    ~Sphere();
    float getIntersection(Ray &ray) override;
    vec3 getNormal(vec3 collisionPoint) override;
private:
    float radius;
    vec3 center;
};
