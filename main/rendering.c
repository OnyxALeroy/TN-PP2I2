#include <SDL2/SDL.h>
#include "rendering.h"

void render_perso(Main_Perso* perso, SDL_Renderer* renderer, SDL_Rect dest) {
    dest.x = perso->x;
    dest.y = perso->y;
    dest.w = perso->width;
    dest.h = perso->height;

    SDL_RenderCopy(renderer, perso->texture, NULL, &dest);
}
