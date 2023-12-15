#include "ParticleSystem.h"
#include "DataCenter.h"
void
ParticleSystem::particle_sys_init()
{

}

void
ParticleSystem::particle_sys_update()
{
    if(DC->get_Player().OnFire()){
        DC->get_ParticleSystem().particle_sys_add(20);
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
        it->particle_render();
    }
}

void
ParticleSystem::particle_sys_add(int num)
{
    for(int i=0; i<num; ++i){
        Particle *p = new Particle();
        p->particle_init();
        p->velocity = mouse_pos - DC->get_Player().GetPos();
        p->velocity = randVec(p->velocity, ALLEGRO_PI/12.0f);
        Normalize(p->velocity);
        p->pos = DC->get_Player().GetPos();
        ammo.emplace_back(p);
    }

}
