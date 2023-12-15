#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "global.h"
#include "tool.h"

const float player_height = 10;
const float player_width = 10;
const float player_speed = 500;
const float player_fly_time = 0.5f;

class Player{
public:
    void player_init(void);
    void player_movement(void);
    void player_attack(void);
    void player_update(void);

    void player_render(void);

    bool OnFire(void) const{ return onFire; }

    Vec2 GetPos(void) const{ return pos; }
    Vec2 GetFlyTime(void) const { return fly_time; }
    Vec2 GetVelocity(void) const { return velocity; }
    CoolDownCounter GetCD(void) const { return shootCD; }

private:
    Vec2 pos;
    Vec2 velocity;
    float health = 0;
    float speed = 0;

    Vec2 fly_time;

    // shooting system
    CoolDownCounter shootCD;
    bool onFire = false;
};

#endif // PLAYER_H_INCLUDED
