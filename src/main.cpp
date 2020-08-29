#include "vec.h"
#include <iostream>

int main()
{
    vec3 a{1.0f,0.0f,0.0f};
    vec3 b{0.0f,1.0f,0.0f};
    vec3 c{1.0f,1.0f,-1.0f};

    float dir = 2.0f;
    vec3 ray = a + dir * c;
    vec3 f = a.cross(b);

    ray.print("d");
    f.print("f");

    return 0;
}
