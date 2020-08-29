#include "vec.h"
#include <iostream>

int main()
{
    vec3 a{1.0f,0.0f,0.0f};
    vec3 b{0.0f,1.0f,0.0f};
    vec3 c{1.0f,1.0f,-1.0f};

    float dir = 2.0f;
    vec3 ray =a + b * dir;
    vec3 f = a.cross(b);

    ray.print("ray");
    f.print("f");

    return 0;
}
