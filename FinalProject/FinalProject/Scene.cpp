#include "Scene.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "global.h"
#include <iostream>

#define GET_W(bitmap) al_get_bitmap_width(bitmap)
#define GET_H(bitmap) al_get_bitmap_height(bitmap);

void
Scene::scene_init()
{
    printf("Scene Initializing...\n");

    auto null_test = [] (void const *a, char const *msg) {
        if(a == NULL){
            fprintf(stderr,"null_test: %s is null.\n" ,msg);
            exit(9);
        }
    };

    scene_floor = al_load_bitmap("../images/bridge2.png");
    null_test(scene_floor, "scene_floor");

    constexpr int w = window_width  + 10;
    constexpr int h = window_height + 10;
    grid_map.resize(h, std::vector<int>(w));

    scene_load_bitmap_to_grid(scene_floor, w, h);
    //exit(9);

}

void
Scene::scene_load_bitmap_to_grid(ALLEGRO_BITMAP* bitmap,const int &grid_w,const int &grid_h)
{
    float width  = GET_W(bitmap);
    float height = GET_H(bitmap);

    auto same_color = [] (ALLEGRO_COLOR x, ALLEGRO_COLOR y){
        return (x.a==y.a && x.r==y.r && x.g==y.g && x.b==y.b);
    };

    // sampling
    al_lock_bitmap( bitmap, al_get_bitmap_format(bitmap) , ALLEGRO_LOCK_READONLY );
    for(int i=0; i<width; ++i) for(int j=0; j<height; ++j){
        if(same_color(al_get_pixel(bitmap,i , j), WHITE)){
            grid_map[i][j] = WALLS;
        }
    }
    al_unlock_bitmap(bitmap);
}

void
Scene::scene_render()
{

    ALLEGRO_TRANSFORM trans, prevTrans;
    // back up the current transform
    al_copy_transform(&prevTrans, al_get_current_transform());

    // scale using the new transform
    al_identity_transform(&trans);
    al_scale_transform(&trans, GRID_SIZE, GRID_SIZE);
    al_use_transform(&trans);

    al_draw_bitmap(scene_floor, 0, 0, 0);

    // restore the old transform
    al_use_transform(&prevTrans);
}

bool
Scene::isCollideWall(const Vec2 &pos, float width, float height)
{
    int x = pos.x / GRID_SIZE, y = pos.y / GRID_SIZE;
    //return grid_map[x][y] == WALLS;
    int p1,p2,p3,p4;
    p1 = pos.x/GRID_SIZE, p2 = (pos.x+width)/GRID_SIZE,
    p3 = pos.y/GRID_SIZE, p4 = (pos.y+height)/GRID_SIZE;

    if(p1&&p3&&p1<grid_map.size()&&p3<grid_map[0].size()&&grid_map[p1][p3] == WALLS)return true;
    if(p1&&p4&&p1<grid_map.size()&&p4<grid_map[0].size()&&grid_map[p1][p4] == WALLS)return true;
    if(p2&&p3&&p2<grid_map.size()&&p3<grid_map[0].size()&&grid_map[p2][p3] == WALLS)return true;
    if(p2&&p4&&p2<grid_map.size()&&p3<grid_map[0].size()&&grid_map[p2][p4] == WALLS)return true;
    return false;
}
