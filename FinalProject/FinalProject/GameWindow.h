#ifndef GAMEWINDOW_H_INCLUDED
#define GAMEWINDOW_H_INCLUDED

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <list>
#include <time.h>

#include "DataPanel.h"
#include "Scene.h"

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7


class GameWindow{
public:
    GameWindow();
    // process of game
    void game_init(void);
    void game_reset(void);
    void game_play(void);
    void game_begin(void);

    int game_run(void);
    int game_update(void);

    void show_err_msg(int msg);
    void game_destroy(void);

    // each drawing scene function
    void render_map(void);

    // process of event
    int process_event(void);
    void handle_user_input(void);
private:
    ALLEGRO_BITMAP *icon;

    ALLEGRO_DISPLAY* display = NULL;

    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;

    DataPanel *DP = new DataPanel();

    bool redraw = false;
    bool mute = false;
};

#endif // GAMEWINDOW_H_INCLUDED
