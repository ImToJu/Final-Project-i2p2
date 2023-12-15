#include "tool.h"
Vec2
Vec2::operator+ (const Vec2 &v) const
{
    return Vec2(x+v.x, y+v.y);
}

Vec2
Vec2::operator- (const Vec2 &v) const
{
    return Vec2(x-v.x, y-v.y);
}

Vec2
Vec2::operator* (const float f) const
{
    return Vec2(x*f, y*f);
}

Vec2
Vec2::operator/ (const float f) const
{
    return Vec2(x/f, y/f);
}

float
Vec2::magnitude() const
{
    return sqrt(x*x + y*y);
}

Vec2
Vec2::normalize() const
{
    Vec2 v = (*this);
    if(v.magnitude() == 0) {
        printf("Normalize_ret() : Divided by zero is not allowed.\n");
        exit(0);
    }
    return v*(1/v.magnitude());
}

float
cross(Vec2 &v1, Vec2 &v2)
{
    return v1.x * v2.y + v1.y * v2.x;
}

void
Normalize(Vec2 &v)
{
    if(v.magnitude() == 0) {
        printf("Normalize_ret() : Divided by zero is not allowed.\n");
        exit(0);
    }
    v = v*(1/v.magnitude());
}

void
RotateVec(Vec2 &v, float rad)
{
    float x = v.x, y = v.y;
    v.x = cos(rad) * x - sin(rad) * y;
    v.y = sin(rad) * x + cos(rad) * y;
}

Vec2
randVec(Vec2 &v, float rad)
{
    Vec2 ret = v;
    RotateVec(ret, rad*(rand01()-0.5));
    return ret;
}

void
Apply_Force(Vec2 &v, Vec2 force, float m, float dt)
{
    v = v + force / (m * dt) ;
}

float
rand01()
{
   return (rand() % 10000) / 10000.0f;
}

void
clamp(float &x, float a, float b)
{
    if(x < a) x = a;
    if(x > b) x = b;
}
