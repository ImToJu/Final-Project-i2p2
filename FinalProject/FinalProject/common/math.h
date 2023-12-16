#pragma once
#include <algorithm>
#include <cmath>

#undef min
#undef max

struct Math
{
    static constexpr float PI    = 3.141592653f;
    static constexpr float TwoPI = 2.0f * PI;

    static float pow(float base, uint32_t exp)
    {
        float res = 1;
        while (exp > 0) {
            if (exp & 1) res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }

    template<typename T>
    static T sign(T v)
    {
        return v < 0.0f ? -1.0f : 1.0f;
    }

    static float radToDeg(float rad)
    {
        constexpr float rad_to_deg = 180.0f / PI;
        return rad * rad_to_deg;
    }

    static float clamp(float v, float min, float max)
    {
        return std::min(std::max(min, v), max);
    }

};


struct Vec2
{
    float x=0, y=0;

    Vec2(float _x = 0, float _y = 0):
        x(_x), y(_y)
    {}
    // +
    Vec2 operator+ (const Vec2 &v) const
    {
        return Vec2(x+v.x, y+v.y);
    }

    // -
    Vec2 operator- (const Vec2 &v) const
    {
        return Vec2(x-v.x, y-v.y);
    }


    // *
    friend Vec2 operator* (const Vec2 &lhs, const float &rhs)
    {
        return Vec2( lhs.x * rhs, lhs.y * rhs );
    }

    friend Vec2 operator* (const float &lhs, const Vec2 &rhs)
    {
        return Vec2( lhs * rhs.x, lhs * rhs.x );
    }

    // /
    Vec2 operator/ (const float &f) const
    {
        return Vec2(x/f, y/f);
    }

    float magnitude(void) const
    {
        return sqrt(x*x + y*y);
    }

    Vec2 normalize(void) const
    {
        Vec2 v = (*this);
        if(v.magnitude() == 0) {
            //fprintf(stderr, "Vec2 normalize(void): Divided by zero is not allowed.\n");
            exit(0);
        }
        return v*(1/v.magnitude());
    }
};

struct MathVec2
{
    static float length2(Vec2 v)
    {
        return v.x * v.x + v.y * v.y;
    }

    static float length(Vec2 v)
    {
        return sqrt(length2(v));
    }

    static float angle(Vec2 v_1, Vec2 v_2 = {1.0f, 0.0f})
    {
        const float dot = v_1.x * v_2.x + v_1.y * v_2.y;
        const float det = v_1.x * v_2.y - v_1.y * v_2.x;
        return atan2(det, dot);
    }

    static float dot(Vec2 v1, Vec2 v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

    static float cross(Vec2 v1, Vec2 v2)
    {
        return v1.x * v2.y - v1.y * v2.x;
    }

    static Vec2 normal(const Vec2& v)
    {
        return {-v.y, v.x};
    }

    static Vec2 rotateDir(const Vec2& v, const Vec2& dir)
    {
        return { dir.x * v.x - dir.y * v.y, dir.y * v.x + dir.x * v.y };
    }

    static Vec2 normalize(const Vec2& v)
    {
        return v / length(v);
    }

    static Vec2 rotateVec(const Vec2 &v, float rad)
    {
        const float cr = cos(rad);
        const float sr = sin(rad);
        return { cr * v.x - sr * v.y, sr * v.x + cr * v.y };
    }

};

struct PhysicVec2
{
    static Vec2 apply_force(const Vec2 &v, const Vec2 force, const float m, const float dt)
    {
        return v + force / (m * dt) ;
    }
};

