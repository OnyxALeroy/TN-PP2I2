#include "defs.h"
#include "draw_snake.h"
#include "snake.h"

void Init_Snake(void) {
    for (int i = 0; i < snake_length; i++) {
        snake_rects[i].x = WIDTH / 2 - i * GRID_SIZE;
        snake_rects[i].y = HEIGHT / 2;
        snake_rects[i].w = snake_rects[i].h = GRID_SIZE;
    }
}

void update_snake(void) {
    for (int i = snake_length - 1; i > 0; i--)
    {
        snake_rects[i] = snake_rects[i - 1];
    }

    switch (current_direction)
    {
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
}
