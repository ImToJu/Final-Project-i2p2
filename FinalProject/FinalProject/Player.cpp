#include "Player.h"
#include "common/math.h"
#include "DataCenter.h"
#include <iostream>

void
Player::player_init()
{

    printf("Player Initializing...\n");

    Object({200, 200}, 40.0f);

    position = last_position = {200, 200};
    speed = player_speed;

    shootCD.resetCD( player_shoot_cd );
    fly_time.resetCD( player_fly_time );
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
            last_position.x -= 2;
        }
    }
    if( key_state[ALLEGRO_KEY_A] && !key_state[ALLEGRO_KEY_D] ){
        input_dir_horizon -= 1;
        if(getVelocity().x > -player_speed){
            last_position.x += 2;
        }
    }
    // vertical input & jump
    if(key_state[ALLEGRO_KEY_SPACE] && fly_time.t > 0){
        fly_time.t -= DTIME;
        if(fly_time.t > 0){
            // gravity * (1 + up acceleration)
            acceleration.y -= 980 * (1 + 0.2f);
        }
    }else{
        fly_time.t += DTIME * 0.4f;
    }
    if(fly_time.t > fly_time.cd){
        fly_time.t = fly_time.cd;
    }
    // apply gravity
    acceleration.y += 980;

    // Shoot Force
    if(onFire){
        Vec2 force_dir = position - mouse_pos;
        force_dir = MathVec2::normalize(force_dir);
        acceleration = acceleration + force_dir * 40000;
    }

    // check collide

    if(DC->get_Scene().isCollideWall(Vec2(last_position.x, position.y + 2), player_height/2, player_height/2)){
        velocity_damping = 600.0f;
    }else{
        velocity_damping = 40.0f;
    }

    Vec2 dx = getVelocity() + acceleration * DTIME * DTIME;
    if(DC->get_Scene().isCollideWall(Vec2(position.x + dx.x, last_position.y), player_height/2, player_height/2)){
        setPositionRemainSpeed(Vec2(position.x + dx.x, last_position.y-GRID_SIZE));
    }


    player_check_wall_collide(position, last_position);
    Vec2 last = position;
    update(DTIME);
    player_check_wall_collide(position, last);

    // confine next position
    position.x = Math::clamp(position.x, 0 + player_width, window_width - player_width);
    position.y = Math::clamp(position.y, 0 + player_height, window_height - player_height);
}

void
Player::player_check_wall_collide(Vec2 &cur_pos, Vec2 &last_pos)
{
    if(DC->get_Scene().isCollideWall(Vec2(cur_pos.x, last_pos.y), player_height/2, player_height/2)){
        cur_pos.x = last_pos.x;
        acceleration.x = 0;
    }
    if(DC->get_Scene().isCollideWall(Vec2(last_pos.x, cur_pos.y), player_height/2, player_height/2)){
        cur_pos.y = last_pos.y;
        acceleration.y = 0;
    }
    if(DC->get_Scene().isCollideWall(cur_pos, player_height/2, player_height/2)){
        cur_pos = last_pos;
        acceleration = Vec2(0, 0);
    }
}

void
Player::player_attack()
{
    if(shootCD.t < shootCD.cd) {
        shootCD.t += DTIME;
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
    al_draw_rectangle(position.x - player_width/2, position.y - player_height/2,
                      position.x + player_width/2, position.y + player_height/2,
                      BLUE, 3);

    if(DC->get_Scene().isCollideWall(position, player_height, player_height)){
        al_draw_circle(position.x, position.y, player_height, WHITE, 3);
    }
    if(DC->get_Scene().isCollideWall(Vec2(last_position.x, position.y + 1), player_height/2, player_height/2)){
        al_draw_circle(position.x, position.y, 5, ORANGE_LIGHT, 3);
    }
    //al_draw_circle(position.x, position.y, player_height, WHITE, 3);
    //if(onFire) al_draw_circle(pos.x, pos.y, 5, ORANGE_LIGHT, 3);
}
