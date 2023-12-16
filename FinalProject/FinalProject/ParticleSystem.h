#ifndef PARTICLESYSTEM_H_INCLUDED
#define PARTICLESYSTEM_H_INCLUDED

#include <list>
#include <algorithm>
#include "global.h"
#include "object/Particle.h"

const int MAX_AMMO = 10000;

class ParticleSystem{
public:
    void particle_sys_init(void);
    void particle_sys_update(void);
    void particle_sys_render(void);

    void particle_sys_add(int num);

    int GetAmmoSize() { return ammo.size(); }

private:
    std::list<Particle*> ammo;

};

#endif // PARTICLESYSTEM_H_INCLUDED
