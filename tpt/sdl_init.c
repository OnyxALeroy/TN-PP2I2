#include <SDL2/SDL.h>
#include "defs.h"
#include "sdl_init.h"


SDL_Renderer *Init_SDL(void){
    // SDL Initialisation //
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in init: %s", SDL_GetError());
        exit(-1);
    }
    atexit(SDL_Quit);

    // Creation fenetre et attribution moteur rendu //
    SDL_Window *window;
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_INPUT_FOCUS);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in window init : %s", SDL_GetError());
        exit(-1);
    }
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in renderer init : %s", SDL_GetError());
        exit(-1);
    }
    return renderer;
}
