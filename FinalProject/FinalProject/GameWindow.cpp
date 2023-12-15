#include "GameWindow.h"
#include "global.h"
#include "DataCenter.h"
#include <iostream>

void
GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);
    printf("Game Initializing...\n");
    display = al_create_display(window_width, window_height);
    al_set_new_display_flags(ALLEGRO_OPENGL);
    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / FPS);

    if(timer == NULL)
        show_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0); //load large font

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    game_init();
}

void
GameWindow::game_init()
{
    DC->get_Player().player_init();
    DC->get_ParticleSystem().particle_sys_init();
    DP->DataPanel_init();
}

int
GameWindow::game_run()
{
    int error = GAME_CONTINUE;
    if (!al_is_event_queue_empty(event_queue)) {
        error = process_event();
    }

    if(key_state[ALLEGRO_KEY_ESCAPE])
        error = GAME_EXIT;

    return error;
}

void
GameWindow::game_play()
{
    int msg;

    // set random seed
    srand(time(NULL));

    msg = -1;
    game_reset();
    game_begin();
    printf("Game Running...\n");
    while(msg != GAME_EXIT)
    {
        msg = game_run();
    }
    show_err_msg(msg);
}

int
GameWindow::game_update()
{
    DC->get_Player().player_update();
    DC->get_ParticleSystem().particle_sys_update();
    return GAME_CONTINUE;
}

void
GameWindow::game_reset()
{
    mute = false;
    redraw = false;

    // stop timer
    al_stop_timer(timer);

}

void
GameWindow::game_begin()
{
    al_start_timer(timer);
}

void
GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);

    al_destroy_bitmap(icon);
    delete DP;
}

int
GameWindow::process_event()
{
    int instruction = GAME_CONTINUE;

    al_wait_for_event(event_queue, &event);


    redraw = false;

    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(event.timer.source == timer) {
            redraw = true;

        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }
    /*TODO:*/
    // process key board state

    handle_user_input();

    // update each object in game
    if(redraw && al_is_event_queue_empty(event_queue)) {
        // Re-draw map
        instruction = game_update();
        render_map();
        redraw = false;
    }
    return instruction;
}

void
GameWindow::handle_user_input()
{
    switch(event.type)
    {
        case ALLEGRO_EVENT_TIMER:
            for(int i = 0; i < 3; i++)
                mouse[i] &= 1;
            mousestate &= 1;
            for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                key_state[i] &= 1;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            mouse[event.mouse.button] = 1 | 2;
            mousestate = 1 | 2;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            mouse[event.mouse.button] &= 2;
            mousestate &= 2;
            break;
        case ALLEGRO_EVENT_MOUSE_AXES:
            mouse_pos.x = event.mouse.x;
            mouse_pos.y = event.mouse.y;
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            key_state[event.keyboard.keycode] = 1 | 2;
            break;
        case ALLEGRO_EVENT_KEY_UP:
            key_state[event.keyboard.keycode] &= 2;
            break;
    }
}

void
GameWindow::render_map()
{
    // reset canva
    al_clear_to_color(BLACK);

    DC->get_Player().player_render();
    DC->get_ParticleSystem().particle_sys_render();
    DP->DataPanel_render();

    // update canva
    al_flip_display();
}
