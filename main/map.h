#include <SDL2/SDL.h>

typedef struct point {
    int x;
    int y;
} Point;

typedef struct main_Perso {
    int x;
    int y;
    int height;
    int width;
    int speed;
    SDL_Texture* texture;
    int direction;
    int sprite_num;
    SDL_Rect** srcs;
    int is_moving;
} Main_Perso;

Main_Perso* create_perso(int x, int y, int speed, SDL_Surface* surface, int dir, SDL_Renderer* renderer, int sprite_num, int src[4][3][4]);

typedef struct tile {
    SDL_Rect rect;
    int is_inside;
} Tile;

typedef struct map {
    int x;
    int y;
    int n;
    int m;
    Tile*** tiles;
    SDL_Texture* sprites_map;
} Map;

Point* create_point(int x, int y);
Tile* create_tile(int x, int y, int height, int width, int inside);
Map* create_map(int x, int y, int n, int m, SDL_Texture* sprites);

void get_basic_coos(Point* mouse_pos, Point* dest, Main_Perso* perso);
void move_tile(Tile* tile, int delta_x, int delta_y);
void move_map(Map* map, int delta_x, int delta_y);
