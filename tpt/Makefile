CC = clang
CFLAGS = -Wall -std=c99 -Wextra -pedantic -fsanitize=address
LDFLAGS = -fsanitize=address
INC_DIR = -I/opt/homebrew/include
LIB_DIR = -L/opt/homebrew/lib
LIBS = -lSDL2

all : main.out

main.out : main.o collision.o graphics.o sdl_init.o
	$(CC) $(LDFLAGS) $(LIB_DIR) -o main.out main.o collision.o graphics.o sdl_init.o $(LIBS)

main.o : main.c
	$(CC) -c $(CFLAGS) $(INC_DIR) main.c defs.h structs.h main.h sdl_init.h graphics.h collision.h

collision.o : collision.c
	$(CC) -c $(CFLAGS) $(INC_DIR) collision.c collision.h defs.h

graphics.o : graphics.c
	$(CC) -c $(CFLAGS) $(INC_DIR) graphics.c graphics.h defs.h

sdl_init.o : sdl_init.c
	$(CC) -c $(CFLAGS) $(INC_DIR) sdl_init.c sdl_init.h defs.h

run : main.out
	./main.out

clean :
	rm -f *.o *.out *.h.gch