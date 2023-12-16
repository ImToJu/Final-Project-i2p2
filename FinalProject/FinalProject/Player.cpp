#include "Player.h"
#include "common/math.h"

void
Player::player_init()
{
    Object({200, 200});
    shootCD.t = 0.0f, shootCD.cd = player_shoot_cd;
    speed = player_speed;
    fly_time = Vec2(0, player_fly_time);
}

void
Player::player_update()
{
    player_movement();

    player_attack();
}

void
Player::player_movement()
{
    // horizon input
    float input_dir_horizon = 0;
    if( key_state[ALLEGRO_KEY_D] && !key_state[ALLEGRO_KEY_A] ){
        input_dir_horizon += 1;
        if(getVelocity().x < player_speed){
            last_position.x -= 1;
        }
    }
    if( key_state[ALLEGRO_KEY_A] && !key_state[ALLEGRO_KEY_D] ){
        input_dir_horizon -= 1;
        if(getVelocity().x > -player_speed){
            last_position.x += 1;
        }
    }
    // vertical input & jump
    if(key_state[ALLEGRO_KEY_SPACE] && fly_time.x > 0){
        fly_time.x -= 2.f/FPS;
        if(fly_time.x < 0){
            fly_time.x = -0.5f;
        }
        if(fly_time.x > 0){
            last_position.y = position.y + 10;
        }
    }
    fly_time.x += 1.f/FPS;
    if(fly_time.x > fly_time.y){
        fly_time.x = fly_time.y;
    }
    // apply gravity
    if(!key_state[ALLEGRO_KEY_SPACE]){
        acceleration.y += 980;
    }

    // check collide


    // Shoot Force
    if(onFire){
        Vec2 force_dir = position - mouse_pos;
        force_dir = MathVec2::normalize(force_dir);
        acceleration = acceleration + force_dir * 40000;
    }

    update(1/FPS);

    // confine next position
    position.x = Math::clamp(position.x, 0 + player_width, window_width - player_width);
    position.y = Math::clamp(position.y, 0 + player_height, window_height - player_height);
}

void
Player::player_attack()
{
    if(shootCD.t < shootCD.cd) {
        shootCD.t += 1.f/FPS;
        onFire = false;
    }
    if(shootCD.t >= shootCD.cd) {
        if(mouse[MOUSE_LEFT]){
            onFire = true;
            shootCD.t = 0;
        }
    }
}

void
Player::player_render()
{
    al_draw_circle(position.x, position.y, player_height, WHITE, 3);
    //if(onFire) al_draw_circle(pos.x, pos.y, 5, ORANGE_LIGHT, 3);
}
