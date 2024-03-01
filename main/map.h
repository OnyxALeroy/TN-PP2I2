#include <SDL2/SDL.h>

#define WIDTH 1280
#define HEIGHT 960

typedef struct main_Perso {
    int x;
    int y;
    int height;
    int width;
    int speed;
    SDL_Texture* texture;
    int is_right;
} Main_Perso;

Main_Perso* create_perso();

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

Tile* create_tile(int x, int y, int height, int width, int inside);
Map* create_map(int x, int y, int n, int m, SDL_Texture* sprites);
