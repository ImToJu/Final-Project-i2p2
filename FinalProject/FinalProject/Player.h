#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "global.h"
#include "object/object.h"

constexpr float player_height = 10;
constexpr float player_width = 10;
constexpr float player_speed = 10;
constexpr float player_fly_time = 0.5f;
constexpr float player_shoot_cd = 0.5f;

class Player : public Object
{
public:

    Player() = default;

    void player_init(void);
    void player_movement(void);
    void player_attack(void);
    void player_update(void);

    void player_render(void);

    bool OnFire(void) const{ return onFire; }

    Vec2 GetPos(void) const{ return position; }
    Vec2 GetFlyTime(void) const { return fly_time; }
    Vec2 GetVelocity(void) const { return getVelocity(); }
    CoolDownCounter GetCD(void) const { return shootCD; }

private:
    float health = 0;
    float speed = 0;

    Vec2 fly_time;

    // shooting system
    CoolDownCounter shootCD;
    bool onFire = false;
};

#endif // PLAYER_H_INCLUDED
