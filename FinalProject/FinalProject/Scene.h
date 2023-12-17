#pragma once

#include "allegro5/bitmap.h"
#include "common/math.h"
#include <vector>

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define AIR 0
#define WALLS 1

const int GRID_SIZE = 8;

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    void scene_init();
    void scene_update();
    void scene_render();

    void scene_load_bitmap_to_grid(ALLEGRO_BITMAP* bitmap, const int& gird_w, const int& grid_h);

    bool isCollideWall(const Vec2 &pos, float width, float height);

private:
    int level = 0;

    std::vector<std::vector<int>> grid_map;

    ALLEGRO_BITMAP* scene_background  = NULL;
    ALLEGRO_BITMAP* scene_floor       = NULL;
    ALLEGRO_BITMAP* scene_frontground = NULL;

};
