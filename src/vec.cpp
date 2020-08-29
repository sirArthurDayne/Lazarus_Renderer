#include "vec.h"
#include <cassert>
#include <cmath>
#include <cstdio>

vec3::vec3() : x(0.0f), y(0.0f),z(0.0f) {}
vec3::~vec3() {}
vec3::vec3(float scalar) : x(scalar), y(scalar),z(scalar) {}
vec3::vec3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
vec3::vec3(vec3& v): x(v.x),y(v.y),z(v.z) {}

vec3 vec3::add(const vec3& other) const
{
    return vec3(x + other.x, y + other.y, z + other.z);
}

vec3 vec3::add(float scalar) const
{
    return vec3(x + scalar, y + scalar, z + scalar);
}

vec3 vec3::subtract(const vec3& other) const
{
    return vec3(x - other.x, y - other.y, z- other.z);
}


vec3 vec3::subtract(float scalar) const
{
    return vec3(x - scalar, y - scalar,z - scalar);
}

vec3 vec3::mult(const vec3& other) const
{
    return vec3(x * other.x, y*other.y, z*other.z);
}

vec3 vec3::mult(float scalar) const
{
    return vec3(x * scalar, y * scalar, z * scalar);
}

vec3 vec3::div(float scalar) const
{
    if(scalar == 0.0f) assert("divide by 0");
    const float over_scalar = 1.0f/scalar;
    return vec3(x *over_scalar, y * over_scalar, z *over_scalar);
}

vec3 vec3::operator+(const vec3& rhs)
{
    return add(rhs);
}


vec3 vec3::operator+(float scalar)
{
    return add(scalar);
}

vec3 vec3::operator-(const vec3& rhs)
{
    return subtract(rhs);
}

vec3 vec3::operator-(float scalar)
{
    return subtract(scalar);
}

vec3 vec3::operator*(float scalar)
{
    return mult(scalar);
}

vec3 vec3::operator/(float scalar)
{
    return div(scalar);
}

vec3& vec3::operator+=(const vec3& rhs)
{
     this->x += rhs.x;
     this->y += rhs.y;
	this->z += rhs.z;
     return *this;
}

vec3& vec3::operator-=(const vec3& rhs)
{
     this->x -= rhs.x;
     this->y -= rhs.y;
     this->z -= rhs.z;
     return *this;
}

vec3& vec3::operator*=(const float rhs)
{
     this->x *= rhs;
     this->y *= rhs;
	this->z *= rhs;
     return *this;
}

vec3& vec3::operator/=(const float rhs)
{
     const float over_rhs = 1.0f / rhs;
     this->x *= over_rhs;
     this->y *= over_rhs;
     this->z *= over_rhs;
     return *this;
}


float vec3::dot(const vec3 &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

float vec3::mag() const
{
    return sqrtf(x*x+y*y+z*z);
}

vec3 vec3::normalize() const
{
    const float over_magnitude = 1.0 / mag();
    return vec3(this->x * over_magnitude, this->y * over_magnitude, this->z *over_magnitude);
}

vec3 vec3::cross(const vec3 &other) const
{
    const float x = this->y * other.z - this->z*other.y;
    const float y = -(this->x*other.z - this->z*other.x);
    const float z = this->x*other.y - this->y*other.x;
    return vec3(x,y,z);
}

void vec3::print(const char* name) const
{
    printf("%s(%f, %f, %f)\n", name, this->x,this->y,this->z);
}
