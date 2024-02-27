#include <SDL2/SDL.h>

// Definition des structures/var/fonctions utilisées (à deplacer dans un .h) //
    // struct :
    typedef struct Point {
        int x;
        int y;
    } Point;
    typedef enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    } Direction;
    // const : 
    int const GRID_SIZE = 20;
    int const INITIAL_SNAKE_LENGTH = 5;
    int const WIDTH = 1280;
    int const HEIGHT = 720;
    // var :
    SDL_Rect snake_rects[1000];
    Point food;
    Direction current_direction;
    int snake_length;
    int game_over;
    int last_move_time;
    // fonction :
    void generate_food(void);
    void update_snake(void);
    void check_collision(void);


int main(void) {
    // Init SDL //
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

    // initialisation var :
    current_direction = RIGHT;
    snake_length = INITIAL_SNAKE_LENGTH;
    game_over = 0;
    last_move_time = SDL_GetTicks();

    // initialisation serpent :
    for (int i = 0; i < snake_length; i++) {
        snake_rects[i].x = WIDTH / 2 - i * GRID_SIZE;
        snake_rects[i].y = HEIGHT / 2;
        snake_rects[i].w = snake_rects[i].h = GRID_SIZE;
    }

    // generation de la premiere nourriture :
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
        const int SNAKE_SPEED = 150; //en ms
        if (!game_over && elapsed_time >= SNAKE_SPEED) {
            update_snake();
            check_collision();
            last_move_time = SDL_GetTicks();
        }

        // fond noir :
        SDL_Color const BACKGROUND_COLOR = {.r = 0x00, .g = 0x00, .b = 0x00, .a = 0xFF};
        if (SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in set render draw color : %s", SDL_GetError());
        }
        if (SDL_RenderClear(renderer)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in render clear : %s", SDL_GetError());
        }

        // Rendu serpent :
        SDL_Color const SNAKE_COLOR = {.r = 0xff, .g=0xff, .b=0xff, .a=0xff};
        for (int i = 0; i < snake_length; i++) {
            if (SDL_SetRenderDrawColor(renderer, SNAKE_COLOR.r, SNAKE_COLOR.g, SNAKE_COLOR.b, SNAKE_COLOR.a)) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in set render draw color snake: %s", SDL_GetError());
            }
            if (SDL_RenderFillRect(renderer, &snake_rects[i])) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in render rect snake : %s", SDL_GetError());
            }
        }

        // Rendu nourriture :
        SDL_Color const FOOD_COLOR = {.r = 0xff, .g=0x00, .b=0xff, .a=0xff};
        SDL_Rect food_rect = {food.x, food.y, GRID_SIZE, GRID_SIZE};
        if (SDL_SetRenderDrawColor(renderer, FOOD_COLOR.r, FOOD_COLOR.g, FOOD_COLOR.b, FOOD_COLOR.a)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in set render draw color food: %s", SDL_GetError());
        }
        if (SDL_RenderFillRect(renderer, &food_rect)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error in render rect food : %s", SDL_GetError());
        }

        // Swap Buffer :
        SDL_RenderPresent(renderer);
    }
}

void generate_food(void) {
    food.x = (rand() % (WIDTH / GRID_SIZE)) * GRID_SIZE;
    food.y = (rand() % (HEIGHT / GRID_SIZE)) * GRID_SIZE;
}

void update_snake(void) {
    for (int i = snake_length - 1; i > 0; i--) {
        snake_rects[i] = snake_rects[i - 1];
    }

    switch (current_direction) {
        case UP:
            snake_rects[0].y -= GRID_SIZE;
            break;
        case DOWN:
            snake_rects[0].y += GRID_SIZE;
            break;
        case LEFT:
            snake_rects[0].x -= GRID_SIZE;
            break;
        case RIGHT:
            snake_rects[0].x += GRID_SIZE;
            break;
    }

    // Vérification de la collision avec la nourriture
    if (snake_rects[0].x == food.x && snake_rects[0].y == food.y) {
        snake_length++;
        generate_food();
    }
}

void check_collision(void) {
    // Collision avec les bords de l'écran
    if (snake_rects[0].x < 0 || snake_rects[0].x >= WIDTH ||
        snake_rects[0].y < 0 || snake_rects[0].y >= HEIGHT) {
        game_over = 1;
    }

    // Collision avec le corps du serpent
    for (int i = 1; i < snake_length; i++) {
        if (snake_rects[0].x == snake_rects[i].x && snake_rects[0].y == snake_rects[i].y) {
            game_over = 1;
            break;
        }
    }
}
