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
        DC->get_ParticleSystem().particle_sys_add(10000);
    }
    // update ammo
    for(auto &it : ammo){
        it.particle_update();
    }

    // delete
    for(auto it = ammo.begin(); it != ammo.end(); ++it){
        if(!it->needDelete()) break;
        ammo.erase(it);
    }
}

void
ParticleSystem::particle_sys_render()
{
    for(auto &it : ammo){
        it.particle_update();
    }
}

void
ParticleSystem::particle_sys_add(int num)
{
    int N = ammo.size() + num;
    ammo.resize(N);
    for(int i=0; i<num; ++i){
        Particle p;
        p.particle_init();
        p.velocity = mouse_pos - DC->get_Player().GetPos();
        p.velocity = randVec(p.velocity, ALLEGRO_PI/12.0f);
        Normalize(p.velocity);
        p.pos = DC->get_Player().GetPos();
        ammo.emplace_back(p);
    }

}
