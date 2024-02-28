CC = clang
CFLAGS = -Wall -std=c99 -Wextra -pedantic -fsanitize=address
LDFLAGS = -fsanitize=address
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
LIBS = -lSDL2 -lSDL2_ttf

all : main.out

main.out : main.o
	$(CC) $(LDFLAGS) $(LIB_DIR) -o main.out main.o $(LIBS)

main.o : main.c
	$(CC) -c $(CFLAGS) $(INC_DIR) main.c main.h

run : main.out
	./main.out

clean :
	rm -f *.o *.out
