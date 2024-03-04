#include <SDL2/SDL.h>
#include "map.h"
#include <math.h>
#include "defs.h"

Point* create_point(int x, int y) {
    Point* point = malloc(sizeof(Point));

    point->x = x;
    point->y = y;

    return point;
}

Main_Perso* create_perso(int x, int y, int speed, SDL_Surface* surface, int dir, SDL_Renderer* renderer, int sprite_num, int src[4][3][4]) {
    Main_Perso* perso = malloc(sizeof(Main_Perso));
    perso->x = x;
    perso->y = y;
    perso->width = 64;
    perso->height = 64;
    perso->speed = speed;
    perso->texture = SDL_CreateTextureFromSurface(renderer, surface);
    perso->direction = dir;
    perso->sprite_num = sprite_num;
    perso->is_moving = 0;

    SDL_Rect** srcs = (SDL_Rect**) malloc(4*sizeof(SDL_Rect*));

    for (int i = 0; i<4; i++) {
        srcs[i] = (SDL_Rect*) malloc(3*sizeof(SDL_Rect));
    }

    for (int i = 0; i<4; i++) {
        for (int j = 0; j<3; j++) {
            srcs[i][j].x = src[i][j][0];
            srcs[i][j].y = src[i][j][1];
            srcs[i][j].w = src[i][j][2];
            srcs[i][j].h = src[i][j][3];
        }
    }

    perso->srcs = srcs;

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

void get_basic_coos(Point* mouse_pos, Point* dest, Main_Perso* perso) {
    SDL_GetMouseState(&(mouse_pos->x), &(mouse_pos->y));

    (dest->x) = (mouse_pos->x) - ((2*(perso->x)+(perso->width))/2);
    (dest->y) = (mouse_pos->y) - ((2*(perso->y)+(perso->height))/2);

    double angle = atan2(dest->y, dest->x);
    
    dest->x = -(perso->speed) * cos(angle);
    dest->y = -(perso->speed) * sin(angle);

    double val = fabs(angle);

    if (val < 3.1415/4) {
        perso->direction = RIGHT;
    }
    else if (val > 3*3.1415/4) {
        perso->direction = LEFT;
    }
    else if ((3.1415/4 <= val) && (val <= (3*3.1415/2)) && (angle <= 0)) {
        perso->direction = UP;
    }
    else {
        perso->direction = DOWN;
    }
    perso->is_moving = 1;
}


void move_tile(Tile* tile, int delta_x, int delta_y) {
    tile->rect.x += delta_x;
    tile->rect.y += delta_y;
}


void move_map(Map* map, int delta_x, int delta_y) {
    for (int i = 0; i<(map->n); i++) {
        for (int j = 0; j<(map->m); j++) {
            move_tile((map->tiles)[i][j], delta_x, delta_y);
        }
    }
}
