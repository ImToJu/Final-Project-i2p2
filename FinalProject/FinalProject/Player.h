#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "global.h"
#include "object/object.h"

constexpr float player_height = 20;
constexpr float player_width = 20;
constexpr float player_speed = 10;
constexpr float player_fly_time = 2.0f;
constexpr float player_shoot_cd = 0.01f;

class Player : public Object
{
public:

    Player() = default;

    void player_init(void);
    void player_attack(void);
    void player_update(void);
    void player_render(void);
    void player_movement(void);

    void player_check_wall_collide(Vec2 &cur_pos, Vec2 &last_pos);

    bool OnFire(void)                const { return onFire;   }
    Vec2 GetPos(void)                const { return position; }
    Vec2 GetVelocity(void)           const { return getVelocity(); }
    CoolDownCounter GetCD(void)      const { return shootCD;  }
    CoolDownCounter GetFlyTime(void) const { return fly_time; }

private:
    float health = 0;
    float speed  = 0;
    CoolDownCounter fly_time;
    CoolDownCounter shootCD;
    bool onFire = false;
};

#endif // PLAYER_H_INCLUDED
