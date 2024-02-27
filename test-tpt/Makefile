CC = clang
CFLAGS = -Wall -std=c99 -Wextra -pedantic -fsanitize=address
LDFLAGS = -fsanitize=address
INC_DIR = -I/opt/homebrew/include
LIB_DIR = -L/opt/homebrew/lib
LIBS = -lSDL2

all : snake.out

snake.out : snake.o
	$(CC) $(LDFLAGS) $(LIB_DIR) -o snake.out snake.o $(LIBS)

snake.o : snake.c
	$(CC) -c $(CFLAGS) $(INC_DIR) snake.c

run : snake.out
	./snake.out

clean :
	rm -f *.o *.out