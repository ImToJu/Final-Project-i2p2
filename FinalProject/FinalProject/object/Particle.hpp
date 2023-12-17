#pragma once

#include "../global.h"
#include "../common/math.h"
#include "object.hpp"

constexpr float ammo_size = 5;
constexpr float ammo_speed = 1000;
constexpr float ammo_life = 3;

class Particle{
public:
    Object particleObject;

    CoolDownCounter lifetime;

    Particle(void) = default;

    void particle_init(void);
    void particle_update(void);
    void particle_render(void);

    bool needDelete(void) const{ return lifetime.t >= lifetime.cd; }

private:
    float speed;
    float radius;
    ALLEGRO_COLOR color = WHITE;
};



