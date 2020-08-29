#pragma once

struct vec3{
    float x,y,z;
    vec3();
    vec3(float scalar);
    vec3(float _x, float _y, float _z);
    vec3(vec3& v);
private:
    vec3 add(vec3& other) const;
    vec3 add(float scalar) const;
    vec3 subtract(vec3& other) const;
    vec3 subtract(float scalar) const;
    vec3 mult(vec3& other) const;
    vec3 mult(float scalar) const;
    vec3 div(float scalar) const;
public:
    vec3 operator+(vec3& rhs)const;
    vec3 operator+(float scalar)const;
    vec3 operator-(vec3& rhs)const;
    vec3 operator-(float scalar)const;
    vec3 operator*(vec3& rhs) const;
    vec3 operator*(float scalar) const;
    vec3 operator/(float scalar) const;
    float dot(vec3& other) const;
    float mag() const;
    vec3 normalize() const;
    vec3 cross(vec3& other) const;
    void print(const char* name) const;
};
