#include "global.h"

bool key_state[ALLEGRO_KEY_MAX] = {false};
bool mouse[ALLEGRO_KEY_MAX] = {false};
unsigned char mousestate;
constexpr float FPS = 60.0f;
constexpr float DTIME = 1/FPS;
Vec2 mouse_pos;
