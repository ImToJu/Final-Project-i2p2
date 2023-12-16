#include "Particle.h"
#include "../DataCenter.h"

void
Particle::particle_init()
{
    lifetime.t = 0, lifetime.cd = ammo_life;

    color = WHITE;

    radius = ammo_size;
}

void
Particle::particle_update()
{
    update(1/FPS);
    lifetime.t += 1.0f/FPS;
}

void
Particle::particle_render()
{
    al_draw_circle(position.x, position.y, 20, color, 3);
    //al_draw_pixel(position.x, position.y, WHITE);
    //al_draw_filled_rectangle(pos.x-2, pos.y-2, pos.x+2, pos.y+2, WHITE);
    //al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_ALPHA);
    //al_draw_filled_rectangle(pos.x-10, pos.y-10, pos.x+10, pos.y+10, al_color_hsl(255, 0.5, 0.2) );
}
