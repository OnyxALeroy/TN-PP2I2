#include <SDL2/SDL.h>
#include "graphics.h"
#include "defs.h"
#include "snake.h"

void update_graphics(SDL_Renderer *renderer){
    // fond noir :
    SDL_Color const BACKGROUND_COLOR = {.r = 0x00, .g = 0x00, .b = 0x00, .a = 0xFF};
    if (SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in set render draw color : %s", SDL_GetError());
    }
    if (SDL_RenderClear(renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in render clear : %s", SDL_GetError());
    }

    // Rendu serpent :
    SDL_Color const SNAKE_COLOR = {.r = 0xff, .g = 0xff, .b = 0xff, .a = 0xff};
    for (int i = 0; i < snake_length; i++) {
        if (SDL_SetRenderDrawColor(renderer, SNAKE_COLOR.r, SNAKE_COLOR.g, SNAKE_COLOR.b, SNAKE_COLOR.a)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in set render draw color snake: %s", SDL_GetError());
        }
        if (SDL_RenderFillRect(renderer, &snake_rects[i])) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in render rect snake : %s", SDL_GetError());
        }
    }

    // Rendu nourriture :
    SDL_Color const FOOD_COLOR = {.r = 0xff, .g = 0x00, .b = 0xff, .a = 0xff};
    SDL_Rect food_rect = {food.x, food.y, GRID_SIZE, GRID_SIZE};
    if (SDL_SetRenderDrawColor(renderer, FOOD_COLOR.r, FOOD_COLOR.g, FOOD_COLOR.b, FOOD_COLOR.a)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in set render draw color food: %s", SDL_GetError());
    }
    if (SDL_RenderFillRect(renderer, &food_rect)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in render rect food : %s", SDL_GetError());
    }
}

