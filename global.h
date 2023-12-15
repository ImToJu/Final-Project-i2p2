#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED


#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include <allegro5/allegro_color.h>//NEW
#include <allegro5/allegro.h>//NEW

#include "tool.h"

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 1920
#define window_height 1080

#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2

extern bool key_state[ALLEGRO_KEY_MAX];
extern bool mouse[ALLEGRO_KEY_MAX];
extern unsigned char mousestate;
struct CoolDownCounter{ float t, cd; };
// clock rate
extern const float FPS;
extern Vec2 mouse_pos;


#endif // GLOBAL_H_INCLUDED

