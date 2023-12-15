#include "Player.h"
void
Player::player_init()
{
    pos = Vec2(200, 200);
    shootCD.t = 0.0f, shootCD.cd = .1f;
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
    // next position
    Vec2 nxt = pos;
    // next velocity
    Vec2 nxtv = velocity;

    // horizon input
    float input_dir_horizon = 0;
    if(key_state[ALLEGRO_KEY_D]){
        input_dir_horizon += 1;
    }
    if(key_state[ALLEGRO_KEY_A]){
        input_dir_horizon -= 1;
    }
    nxt.x += input_dir_horizon * 10;

    // vertical input & jump
    if(key_state[ALLEGRO_KEY_SPACE] && fly_time.x > 0){
        fly_time.x -= 2.f/FPS;
        if(fly_time.x < 0){
            fly_time.x = -0.5f;
        }
        if(fly_time.x > 0)
            nxtv.y = -500;
        //Vec2::Apply_Force(nxtv, Vec2(0, -1), 10, 1.0/FPS);
    }
    fly_time.x += 1.f/FPS;
    if(fly_time.x > fly_time.y){
        fly_time.x = fly_time.y;
    }
    // apply gravity
    if(!key_state[ALLEGRO_KEY_SPACE]){
        nxtv.y += 980 / FPS;
    }

    // Shoot Force
    if(onFire){
        Vec2 force_dir = pos - mouse_pos;
        Normalize(force_dir);
        Apply_Force(nxtv, force_dir, 1, 1.0/FPS);
    }

    velocity = nxtv;
    // update next position by velocity
    nxt = nxt + velocity / FPS;

    // check collide

    // confine next position
    Vec2 prev_pos = nxt;
    clamp(nxt.x, 0 + player_width, window_width - player_width);
    clamp(nxt.y, 0 + player_height, window_height - player_height);

    // if collide with something, reset velocity
    if(prev_pos.x != nxt.x) velocity.x = 0;
    if(prev_pos.y != nxt.y) velocity.y = 0;

    pos = nxt;
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
    al_draw_circle(pos.x, pos.y, player_height, WHITE, 3);
    //if(onFire) al_draw_circle(pos.x, pos.y, 5, ORANGE_LIGHT, 3);
}
