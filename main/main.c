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
    Main_Perso* perso = create_perso(WIDTH/2, HEIGHT/2, 3, surf_perso, 1, renderer);
    SDL_FreeSurface(surf_perso);

    SDL_Rect bloc_perso;

    int x2;
    int y2;

    int xc, yc;
    double gap_x, gap_y, delta_x, delta_y, alpha = 0;


    SDL_Surface* surf_map = SDL_LoadBMP("../assets/test_map.bmp");
    SDL_Texture* text_map = SDL_CreateTextureFromSurface(renderer, surf_map);
    SDL_FreeSurface(surf_map);
    Map* supp_map = create_map(0, 0, 7*32, 7*44, text_map);;
    Map* test_map = create_map(WIDTH/2 - 7*16, HEIGHT/2 - 7*22, 7*32, 7*44, text_map);

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
                continue;

            case SDL_MOUSEBUTTONDOWN:
                follow = 1;
                continue;

            case SDL_MOUSEBUTTONUP:
                follow = 0;
                gap_x = 0;
                gap_y = 0;
                continue;

            case SDL_MOUSEMOTION:
                if (follow) {
                    SDL_GetMouseState(&xc, &yc);

                    delta_x = xc - ((2*(perso->x)+(perso->width))/2);
                    delta_y = yc - ((2*(perso->y)+(perso->height))/2);

                    alpha = atan2(delta_y, delta_x);

                    gap_x = (perso->speed)*cos(alpha);
                    gap_y = (perso->speed)*sin(alpha);
                }
                continue;

            default:
                break;
            }
        }
        // mobs et interactions

        // changements états

        (perso->x) += gap_x;
        (perso->y) += gap_y;

        //rendu graphique

        SDL_RenderClear(renderer);

        render_map(test_map, renderer, supp_map);
        render_perso(perso, renderer, bloc_perso);
        

        SDL_Delay(20);

        SDL_RenderPresent(renderer);
    }

    return 0;
}