#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include "rendering.h"

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in init: %s", SDL_GetError());
        exit(-1);
    }

    SDL_Window* window;
    window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in window init: %s", SDL_GetError());
        exit(-1);
    }
    
    SDL_Renderer* renderer;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in renderer init: %s", SDL_GetError());
        exit(-1);
    }


    // INITS //////////////////////////////////////////////////////////////////////

    SDL_Surface* surf_perso = SDL_LoadBMP("../assets/perso.bmp");
    Main_Perso* perso = create_perso(WIDTH/2, HEIGHT/2, 1, surf_perso, 1, renderer);
    SDL_FreeSurface(surf_perso);

    SDL_Rect bloc_perso;

    int x2;
    int y2;

    int xc, yc;

    ///////////////////////////////////////////////////////////////////////////////

    SDL_Event event;
    int running = 1;
    int follow = 0;

    while (running)
    {
        if (SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                follow = 1;
                break;
            case SDL_MOUSEBUTTONUP:
                follow = 0;
                break;
            default:
                break;
            }
        }
        // mobs et interactions

        // changements états

        Uint32 buttons = SDL_GetMouseState(&xc, &yc);

        if (follow) {
            double delta_x = xc - (perso->x);
            double delta_y = yc - (perso->y);

            double alpha = atan(delta_y/delta_x);

            int gap_x = (perso->speed)*cos(alpha);
            int gap_y = (perso->speed)*sin(alpha);

            (perso->x) += gap_x;
            (perso->y) += gap_y;
        }

        //rendu graphique

        SDL_RenderClear(renderer);

        printf("%d, %d\n\n", xc, yc);
        render_perso(perso, renderer, bloc_perso);

        SDL_Delay(50);

        SDL_RenderPresent(renderer);
    }

    return 0;
}
