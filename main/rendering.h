#include <SDL2/SDL.h>
#include "map.h"

void render_perso(Main_Perso* main_perso, SDL_Renderer* renderer, SDL_Rect dest);
void render_perso_animated(Main_Perso* perso, SDL_Renderer* renderer, SDL_Rect dest, int time);

void render_map(Map* map, SDL_Renderer* renderer, Map* map_supp);
