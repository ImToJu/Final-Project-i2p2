#ifndef _TOOL_H_
#define _TOOL_H_
#include <cmath>
#include <iostream>
#include <time.h>
class Vec2{
public:
    float x=0, y=0;
    Vec2(): x(0), y(0) {}
    Vec2(float _x, float _y): x(_x), y(_y) {}
    Vec2 operator+ (const Vec2 &v) const;
    Vec2 operator- (const Vec2 &v) const;
    Vec2 operator* (const float f) const;
    Vec2 operator/ (const float f) const;
    float magnitude(void) const;
    Vec2 normalize(void) const;
};

float cross(Vec2 &v1, Vec2 &v2);
void Normalize(Vec2 &v);
void RotateVec(Vec2 &v, float rad);
Vec2 randVec(Vec2 &v, float rad);
void Apply_Force(Vec2 &v, Vec2 force, float m, float dt);

float rand01(void);
void clamp(float &x, float a, float b);

#endif // _TOOL_H_
