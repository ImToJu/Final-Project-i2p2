#pragma once

#include "../global.h"
#include "../common/math.h"
#include "object.h"

constexpr float ammo_size = 5;
constexpr float ammo_speed = 10;
constexpr float ammo_life = 3;

class Particle : public Object
{
public:
    float speed;
    CoolDownCounter lifetime;

    Particle(Vec2 pos)
    : Object(pos)
    {
        particle_init();
    }

    void particle_init();
    void particle_update(void);
    void particle_render(void);

    bool needDelete(void) const{ return lifetime.t >= lifetime.cd; }

private:
    float radius;
    ALLEGRO_COLOR color = WHITE;
};



