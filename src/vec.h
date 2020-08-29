#pragma once

struct vec3{
    float x,y,z;
    vec3();
    ~vec3();
    vec3(float scalar);
    vec3(float _x, float _y, float _z);
    vec3(const vec3& v);
private:
    vec3 add(const vec3& other) const;
    vec3 add(float scalar) const;
    vec3 subtract(const vec3& other) const;
    vec3 subtract(float scalar) const;
    vec3 mult(const vec3& other) const;
    vec3 mult(float scalar)const;
    vec3 div(float scalar)const;
public:
    vec3 operator+(const vec3& rhs);
    vec3 operator+(float scalar);
    vec3 operator-(const vec3& rhs);
    vec3 operator-(float scalar);
    vec3 operator*(float scalar) ;
    vec3 operator/(float scalar);
    vec3& operator+=(const vec3& rhs);
    vec3& operator-=(const vec3& rhs);
    vec3& operator*=(const float rhs);
    vec3& operator/=(const float rhs);
    float dot(const vec3& other) const;
    float mag() const;
    vec3 normalize() const;
    vec3 cross(const vec3& other) const;
    vec3 interpolate(const vec3& other, float scalar) const;
    void print(const char* name) const;
};
