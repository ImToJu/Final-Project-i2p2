#pragma once

#include "../common/math.h"

class Object
{
public:
    Vec2 position;
    Vec2 last_position;
    Vec2 acceleration;
    float velocity_damping = 40.0f;

    Object() {};

    explicit
    Object(Vec2 pos, float damping)
        : position(pos)
        , last_position(pos)
        , velocity_damping(damping)
    {}

    void setDamping(float damping)
    {
        velocity_damping = damping;
    }

    void setPosition(Vec2 pos)
    {
        position      = pos;
        last_position = pos;
    }

    void update(float dt)
    {
        const Vec2 dx = position - last_position;

        const Vec2 new_position = position + dx + (acceleration - dx * velocity_damping) * (dt * dt);
        last_position           = position;
        position                = new_position;
        acceleration = {0.0f, 0.0f};
    }

    void stop()
    {
        last_position = position;
    }

    void slowdown(float ratio)
    {
        last_position = last_position + ratio * (position - last_position);
    }

    float getSpeed() const
    {
        return MathVec2::length(position - last_position);
    }

    Vec2 getVelocity() const
    {
        return position - last_position;
    }

    void addVelocity(Vec2 v)
    {
        last_position = last_position - v;
    }

    void confineVelocity(float threshold)
    {
        if(getSpeed() > threshold){
            last_position = position;
            Vec2 v = MathVec2::normalize(getVelocity()) * threshold;
            addVelocity(v);
        }
    }

    void setPositionRemainSpeed(Vec2 new_position)
    {
        const Vec2 to_last = last_position - position;
        position           = new_position;
        last_position      = position + to_last;
    }

    void move(Vec2 dx)
    {
        position = position + dx;
    }
};
