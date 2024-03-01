#include "generate_food.h"
#include "defs.h"
#include "snake.h"

void generate_food(void) {
    food.x = (rand() % (WIDTH / GRID_SIZE)) * GRID_SIZE;
    food.y = (rand() % (HEIGHT / GRID_SIZE)) * GRID_SIZE;
}
