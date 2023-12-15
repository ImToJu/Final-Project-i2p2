#include "Particle.h"

void
Particle::particle_init()
{
    pos = Vec2(0, 0);
    velocity = Vec2(0, 0);
    speed = ammo_speed * (rand01() + 0.5f);
    lifetime.t = 0, lifetime.cd = ammo_life;
    color = WHITE;//NEW
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


    //al_draw_filled_rectangle(pos.x-2, pos.y-2, pos.x+2, pos.y+2, WHITE); //ORIGIN
    al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_ALPHA);
    al_draw_filled_rectangle(pos.x-10, pos.y-10, pos.x+10, pos.y+10, al_color_hsl(255, 0.5, 0.2) );
    al_draw_filled_rectangle(pos.x-10, pos.y-10, pos.x+10, pos.y+10, al_color_hsl(155, 0.5, 0.2) );

  //  al_draw_filled_rectangle(pos.x-0, pos.y-0, pos.x+100, pos.y+100,al_color_hsl(250, 0.000004, 0.5) );//NEW

//al_draw_pixel(pos.x, pos.y, WHITE);
//al_draw_pixel(pos.x, pos.y, BLUE);
    //al_color_rgb_to_hsl(float red, float green, float blue,float *hue, float *saturation, float *lightness)






}
