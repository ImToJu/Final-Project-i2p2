#include "global.h"

bool key_state[ALLEGRO_KEY_MAX] = {false};
bool mouse[ALLEGRO_KEY_MAX] = {false};
unsigned char mousestate;
const float FPS = 60;
Vec2 mouse_pos;
