#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "global.h"
#include "tool.h"

const float ammo_size = 5;
const float ammo_speed = 1000;
const float ammo_life = 3;

class Particle{
public:
    Vec2 pos, velocity;
    CoolDownCounter lifetime;
    Particle(void) {}
    //Particle(Vec2 p, Vec2 v, float s, Vec2 l, ALLEGRO_COLOR c): pos(p), velocity(v), speed(s), lifetime(l), color(c) {}
    void particle_init(void);
    void particle_update(void);
    void particle_render(void);

    bool needDelete(void) const{ return lifetime.t >= lifetime.cd; }

private:
    float speed;
    float radius;
    ALLEGRO_COLOR color = WHITE;
};

#endif // PARTICLE_H_INCLUDED


