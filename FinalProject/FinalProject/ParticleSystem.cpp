#include "ParticleSystem.h"
#include "DataCenter.h"
void
ParticleSystem::particle_sys_init()
{
    printf("Particle System Initializing...\n");
}

void
ParticleSystem::particle_sys_update()
{
    if(DC->get_Player().OnFire()){
        DC->get_ParticleSystem().particle_sys_add(100);
    }
    // update ammo
    for(auto it : ammo){
        it->particle_update();
    }

    // delete
    while(!ammo.empty() && ammo.front()->needDelete()){
        Particle *a = ammo.front();
        ammo.pop_front();
        delete a;
    }
}

void
ParticleSystem::particle_sys_render()
{
    for(auto it : ammo){
        if(it->position.x < window_width  + 100 && it->position.x > -100
        && it->position.y < window_height + 100 && it->position.y > -100)
        it->particle_render();
    }
}

void
ParticleSystem::particle_sys_add(int num)
{
    for(int i=0; i<num; ++i){
        Particle *p = new Particle(DC->get_Player().GetPos(), AMMO_DAMPING);

        Vec2 v = MathVec2::normalize(mouse_pos - DC->get_Player().GetPos());

        float r = DC->get_rng().getRange(ALLEGRO_PI/6.0f);
        v = MathVec2::rotateVec(v, r);

        r = DC->get_rng().getRange(0.5f, 1.5f);
        p->addVelocity(v * r * ammo_speed);

        ammo.emplace_back(p);
    }

}
