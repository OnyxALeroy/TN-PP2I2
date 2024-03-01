CC = clang
CFLAGS = -Wall -std=c99 -Wextra -pedantic -fsanitize=address
LDFLAGS = -fsanitize=address
INC_DIR = -I/opt/homebrew/include
LIB_DIR = -L/opt/homebrew/lib
LIBS = -lSDL2

all : snake.out

snake.out : snake.o collision.o draw_snake.o generate_food.o graphics.o sdl_init.o
	$(CC) $(LDFLAGS) $(LIB_DIR) -o snake.out snake.o collision.o draw_snake.o generate_food.o graphics.o sdl_init.o $(LIBS)

snake.o : snake.c
	$(CC) -c $(CFLAGS) $(INC_DIR) snake.c defs.h structs.h snake.h sdl_init.h draw_snake.h graphics.h collision.h generate_food.h 

collision.o : collision.c
	$(CC) -c $(CFLAGS) $(INC_DIR) collision.c collision.h defs.h

draw_snake.o : draw_snake.c
	$(CC) -c $(CFLAGS) $(INC_DIR) draw_snake.c draw_snake.h defs.h

generate_food.o : generate_food.c
	$(CC) -c $(CFLAGS) $(INC_DIR) generate_food.c generate_food.h defs.h

graphics.o : graphics.c
	$(CC) -c $(CFLAGS) $(INC_DIR) graphics.c graphics.h defs.h

sdl_init.o : sdl_init.c
	$(CC) -c $(CFLAGS) $(INC_DIR) sdl_init.c sdl_init.h defs.h

run : snake.out
	./snake.out

clean :
	rm -f *.o *.out *.h.gch