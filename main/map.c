#include <SDL2/SDL.h>
#include "map.h"

Main_Perso* create_perso(int x, int y, int speed, SDL_Surface* surface, int is_right, SDL_Renderer* renderer) {
    Main_Perso* perso = malloc(sizeof(Main_Perso));
    perso->x = x;
    perso->y = y;
    perso->width = 64;
    perso->height = 64;
    perso->speed = speed;
    perso->texture = SDL_CreateTextureFromSurface(renderer, surface);
    perso->is_right = is_right;

    return perso;
}

Tile* create_tile(int x, int y, int height, int width, int inside) {
    Tile* tile = malloc(sizeof(Tile));

    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    tile->rect = rect;
    tile->is_inside = inside;

    return tile;
}

Map* create_map(int x, int y, int n, int m, SDL_Texture* sprites) {
    Map* map = malloc(sizeof(Map));

    map->x = x;
    map->y = y;
    map->n = n;
    map->m = m;
    
    Tile*** tiles = (Tile***) malloc(n*sizeof(Tile**));
    for (int k = 0; k<n; k++) {
        tiles[k] = (Tile**) malloc(m*sizeof(Tile*));
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            tiles[i][j] = create_tile(x+i*16, y+j*16, 16, 16, 0);
        }
    }

    map->tiles = tiles;
    map->sprites_map = sprites;

    return map;
}
