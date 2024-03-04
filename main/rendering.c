#include <SDL2/SDL.h>
#include "rendering.h"
#include <time.h>
#include "defs.h"

void render_perso(Main_Perso* perso, SDL_Renderer* renderer, SDL_Rect dest) {
    int dir = (perso->direction);
    int sprite_num = 0;
    
    SDL_Rect src = (perso->srcs)[dir][sprite_num];

    dest.x = (perso->x);
    dest.y = (perso->y);
    dest.w = (src.w);
    dest.h = (src.h);
    perso->height = (src.h);
    perso->width = (src.w);

    SDL_RenderCopy(renderer, perso->texture, &src, &dest);
}

void render_perso_animated(Main_Perso* perso, SDL_Renderer* renderer, SDL_Rect dest, int time) {
    int dir = (perso->direction);
    int sprite_num = (perso->sprite_num);
    
    SDL_Rect src = (perso->srcs)[dir][sprite_num];

    dest.x = (perso->x);
    dest.y = (perso->y);
    dest.w = (src.w);
    dest.h = (src.h);
    perso->height = (src.h);
    perso->width = (src.w);

    int part = time % 1000 / 333;
    if (part == 0) {
        (perso->sprite_num) = 0;
    } 
    else if (part == 1) {
        (perso->sprite_num) = 1;
    } 
    else {
        (perso->sprite_num) = 2;
    }

    SDL_RenderCopy(renderer, perso->texture, &src, &dest);
}

void render_map(Map* map, SDL_Renderer* renderer, Map* map_supp) {
    for (int i = 0; i<(map->n); i++) {
        for (int j = 0; j<(map->m); j++) {
            SDL_RenderCopy(renderer, map->sprites_map, &(((map_supp->tiles)[i][j])->rect), &(((map->tiles)[i][j])->rect));
        }
    }
}
