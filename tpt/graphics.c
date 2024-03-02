#include <SDL2/SDL.h>
#include "graphics.h"
#include "defs.h"
#include "main.h"

void update_graphics(SDL_Renderer *renderer){
    // fond noir :
    SDL_Color const BACKGROUND_COLOR = {.r = 0x00, .g = 0x00, .b = 0x00, .a = 0xFF};
    if (SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in set render draw color : %s", SDL_GetError());
    }
    if (SDL_RenderClear(renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in render clear : %s", SDL_GetError());
    }

    // rendu des éléments
}

