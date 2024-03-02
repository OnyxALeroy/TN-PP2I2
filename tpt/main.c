#include <SDL2/SDL.h>
#include "defs.h"
#include "main.h"
#include "sdl_init.h"
#include "graphics.h"
#include "collision.h"

int main(void) {
    // Création d'une fenetre et initialisation du renderer :
    SDL_Renderer *renderer = Init_SDL();

    SDL_Event event;
    int running = 1;
    while (running) {
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        running = 0;
                    }
                    break;
                default :
                    break;
            }
        }

        update_graphics(renderer);

        // Swap Buffer :
        SDL_RenderPresent(renderer);
    }
}

