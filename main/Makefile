CC = clang
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g3
LDFLAGS =
LIBS = -I/usr/lib/cmake/SDL2 -lSDL2 -lm

main: main.o rendering.o map.o
	clang -o main $(LDFLAGS) main.o rendering.o map.o $(LIBS)

main.o: main.c
	clang -c $(CFLAGS) main.c

rendering.o: rendering.c rendering.h
	clang -c $(CFLAGS) rendering.c

map.o: map.c map.h
	clang -c $(CFLAGS) map.c

clean:
	rm -f main main.o rendering.o map.o

run: main
	./main