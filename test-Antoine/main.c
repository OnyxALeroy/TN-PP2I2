#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void SDL_Initialisation(void){
    if (SDL_Init(SDL_INIT_EVERYTHING)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in init: %s\n", SDL_GetError());
        exit(-1);
    }
    atexit(SDL_Quit);

    printf("F\n");

    if (TTF_Init()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in font init: %s\n", TTF_GetError());
        exit(-1);
    }
    atexit(TTF_Quit);
}

int run_game(void){
    SDL_Initialisation();

    SDL_Event event;
    int running = 1;

    while (running){
        if (SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                running =0;
                break;
            case SDL_KEYUP:
                // Key control
                break;
            
            default:
                break;
            }
        }
    }
    return 0;
}

int main(void){
    run_game();
    printf("0;\n");
    return 0;
}
