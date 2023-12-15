#ifndef _DATACENTER_H_
#define _DATACENTER_H_
#include <vector>
#include <list>
#include "Player.h"
#include "ParticleSystem.h"

class DataCenter{
public:
    Player& get_Player()
    {
        return player;
    }
    ParticleSystem& get_ParticleSystem()
    {
        return particleSystem;
    }
private:
    Player player;
    ParticleSystem particleSystem;
};

extern DataCenter* const DC;

#endif //_DATACENTER_H_
