#pragma once

#include "../common/math.h"
#include "../common/vec2.h"

struct Object
{
    Vec2 position;
    Vec2 last_position;
    Vec2 acceleration;

    Object() = default;

    explicit
    Object(Vec2 _position)
        : position(_position)
        , last_position(_position)
    {}

    void setPosition(Vec2 pos)
    {
        position      = pos;
        last_position = pos;
    }

    void update(float dt)
    {
        const Vec2 dx = position - last_position;

        // air friction
        constexpr float VELOCITY_DAMPING = 40.0f;

        const Vec2 new_position = position + dx + (acceleration - dx * VELOCITY_DAMPING) * (dt * dt);
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
        last_position -= v;
    }

    void setPositionRemainSpeed(Vec2 new_position)
    {
        const Vec2 to_last = last_position - position;
        position           = new_position;
        last_position      = position + to_last;
    }

    void move(Vec2 dx)
    {
        position += dx;
    }
};
