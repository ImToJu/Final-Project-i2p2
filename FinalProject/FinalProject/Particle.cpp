#include "Particle.h"

void
Particle::particle_init()
{
    pos = Vec2(0, 0);
    velocity = Vec2(0, 0);
    speed = ammo_speed * (rand01() + 0.5f);
    lifetime.t = 0, lifetime.cd = ammo_life;
    color = WHITE;
    radius = ammo_size;
}

void
Particle::particle_update()
{
    pos = pos + velocity/FPS * speed;
    lifetime.t += 1.0f/FPS;
}

void
Particle::particle_render()
{
    //al_draw_circle(pos.x, pos.y, radius, color, 3);
    al_draw_pixel(pos.x, pos.y, WHITE);
    //al_draw_filled_rectangle(pos.x-2, pos.y-2, pos.x+2, pos.y+2, WHITE);
}
