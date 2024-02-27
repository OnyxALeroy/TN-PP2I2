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
