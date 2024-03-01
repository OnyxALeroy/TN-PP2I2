#include <SDL2/SDL.h>
#include "defs.h"
#include "snake.h"
#include "sdl_init.h"
#include "draw_snake.h"
#include "graphics.h"
#include "collision.h"
#include "generate_food.h"

int main(void) {
    // Création d'une fenetre et initialisation du renderer :
    SDL_Renderer *renderer = Init_SDL();
    
    // initialisation var :
    current_direction = RIGHT;
    snake_length = INITIAL_SNAKE_LENGTH;
    game_over = 0;
    last_move_time = SDL_GetTicks();

    Init_Snake();

    generate_food();

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
                        case SDLK_z:
                            if (current_direction != DOWN) {current_direction = UP;}
                            break;
                        case SDLK_s:
                            if (current_direction != UP) {current_direction = DOWN;}
                            break;
                        case SDLK_q:
                            if (current_direction != RIGHT) {current_direction = LEFT;}
                            break;
                        case SDLK_d:
                            if (current_direction != LEFT) {current_direction = RIGHT;}
                            break;
                    }
                    break;
                default :
                    break;
            }
        }

        int elapsed_time = SDL_GetTicks() - last_move_time;
        if (!game_over && elapsed_time >= SNAKE_SPEED) {
            update_snake();
            check_collision();
            last_move_time = SDL_GetTicks();
        }

        update_graphics(renderer);

        // Swap Buffer :
        SDL_RenderPresent(renderer);
    }
}

