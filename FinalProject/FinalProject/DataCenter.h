#ifndef _DATACENTER_H_
#define _DATACENTER_H_
#include "Player.h"
#include "ParticleSystem.h"
#include "common/random_number.h"

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

    RNGf& get_rng()
    {
        return rngf;
    }
private:
    Player player;
    ParticleSystem particleSystem;
    RNGf rngf;
};

extern DataCenter* const DC;

#endif //_DATACENTER_H_
