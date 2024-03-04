CC = clang
CFLAGS = -Wall -std=c99 -Wextra -pedantic -fsanitize=address -Wnewline-eof
LDFLAGS = -fsanitize=address -Wnewline-eof
INC_DIR =
LIB_DIR =
ifeq ($(shell uname),Darwin)
	INC_DIR += -I/opt/homebrew/include
	LIB_DIR += -L/opt/homebrew/lib
endif
ifeq ($(shell uname),Linux)
	INC_DIR += -I/usr/include
	LIB_DIR += -L/usr/lib
endif
LIBS = -lSDL2

all: main.out

main.out: main.o rendering.o map.o sdl_init.o
	$(CC) $(LDFLAGS) $(LIB_DIR) -o main.out main.o rendering.o map.o sdl_init.o $(LIBS)

main.o: main.c
	$(CC) -c $(CFLAGS) $(INC_DIR) main.c sdl_init.h rendering.h defs.h

rendering.o: rendering.c rendering.h
	$(CC) -c $(CFLAGS) $(INC_DIR) rendering.c rendering.h defs.h

map.o: map.c map.h
	$(CC) -c $(CFLAGS) $(INC_DIR) map.c map.h defs.h

sdl_init.o: sdl_init.c sdl_init.h
	$(CC) -c $(CFLAGS) $(INC_DIR) sdl_init.c sdl_init.h defs.h

clean:
	rm -f *.o *.out *.h.gch

run: main.out
	./main.out