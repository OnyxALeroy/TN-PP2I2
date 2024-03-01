#include <SDL2/SDL.h>
#include "rendering.h"

void render_perso(Main_Perso* perso, SDL_Renderer* renderer, SDL_Rect dest) {
    dest.x = (perso->x);
    dest.y = (perso->y);
    dest.w = (perso->width);
    dest.h = (perso->height);

    SDL_RenderCopy(renderer, perso->texture, NULL, &dest);
}

void render_map(Map* map, SDL_Renderer* renderer, Map* map_supp) {
    for (int i = 0; i<(map->n); i++) {
        for (int j = 0; j<(map->m); j++) {
            SDL_RenderCopy(renderer, map->sprites_map, &(((map_supp->tiles)[i][j])->rect), &(((map->tiles)[i][j])->rect));
        }
    }
}