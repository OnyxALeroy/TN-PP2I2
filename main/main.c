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

    double time = 0;

    SDL_Surface* surf_perso = SDL_LoadBMP("../assets/persos.bmp");
    int sprites_perso[4][3][4] = {
        {
            {66, 0, 26, 44}, {386, 128, 26, 44}, {416, 126, 28, 44}
        },
        {
            {30, 0, 32, 44}, {254, 128, 30, 44}, {222, 126, 32, 46}
        },
        {
            {0, 0, 26, 44}, {0, 128, 26, 44}, {32, 126, 28, 44}
        },
        {
            {94, 0, 52, 44}, {576, 126, 30, 44}, {608, 128, 30, 44}
        }
    };
    Main_Perso* perso = create_perso(WIDTH/2, HEIGHT/2, 3, surf_perso, 3, renderer, 0, sprites_perso);
    SDL_FreeSurface(surf_perso);

    SDL_Rect dest_perso;

    Point* mouse_coos = create_point(0, 0);
    Point* gaps = create_point(0, 0);

    SDL_Surface* surf_map = SDL_LoadBMP("../assets/test_map.bmp");
    SDL_Texture* text_map = SDL_CreateTextureFromSurface(renderer, surf_map);
    SDL_FreeSurface(surf_map);
    Map* supp_map = create_map(0, 0, 7*32, 7*44, text_map);
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
                gaps->x = 0;
                gaps->y = 0;
                perso->is_moving = 0;
                continue;

            case SDL_MOUSEMOTION:
                if (follow) {
                    get_basic_coos(mouse_coos, gaps, perso);
                }
                continue;

            default:
                break;
            }
        }
        // mobs et interactions

        // changements états

        time = SDL_GetTicks();

        if (follow) {
            move_map(test_map, gaps->x, gaps->y);
        }

        //rendu graphique

        SDL_RenderClear(renderer);

        render_map(test_map, renderer, supp_map);
        if (perso->is_moving) {
            render_perso_animated(perso, renderer, dest_perso, time);
        }
        else {
            render_perso(perso, renderer, dest_perso);
        }
        

        SDL_Delay(20);

        SDL_RenderPresent(renderer);
    }

    return 0;
}
