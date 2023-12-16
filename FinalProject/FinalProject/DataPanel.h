#ifndef _DATAPANEL_H_
#define _DATAPANEL_H_

#include <allegro5/allegro_font.h>

class DataPanel{
public:
    void DataPanel_init();
    void DataPanel_render();
private:
    ALLEGRO_FONT *font = NULL;
};


#endif // _DATAPANEL_H_
