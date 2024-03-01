#include "collision.h"
#include "defs.h"
#include "snake.h"

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
