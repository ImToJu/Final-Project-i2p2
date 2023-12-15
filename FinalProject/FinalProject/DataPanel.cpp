#include "DataPanel.h"
#include <string>
#include "DataCenter.h"
#include "Player.h"

void
DataPanel::DataPanel_init()
{
    font = al_load_ttf_font("./font/Consolas.ttf", 20, 0);
    if(font==NULL){ exit(9); }
}

void
DataPanel::DataPanel_render()
{
    char str[100];
    sprintf(str, "fly_time.x: %f", DC->get_Player().GetFlyTime().x);
    al_draw_text(font, WHITE, 10, 100, 0, str);
    sprintf(str, "fly_time.y: %f", DC->get_Player().GetFlyTime().y);
    al_draw_text(font, WHITE, 10, 120, 0, str);
    sprintf(str, "velocity.x: %f", DC->get_Player().GetVelocity().x);
    al_draw_text(font, WHITE, 10, 140, 0, str);
    sprintf(str, "velocity.y: %f", DC->get_Player().GetVelocity().y);
    al_draw_text(font, WHITE, 10, 160, 0, str);

    sprintf(str, "shootCD.t: %f", DC->get_Player().GetCD().t);
    al_draw_text(font, WHITE, 10, 180, 0, str);
    sprintf(str, "shootCD.cd: %f", DC->get_Player().GetCD().cd);
    al_draw_text(font, WHITE, 10, 200, 0, str);

    sprintf(str, "Ammo Num: %d", DC->get_ParticleSystem().GetAmmoSize());
    al_draw_text(font, WHITE, 10, 220, 0, str);
}
