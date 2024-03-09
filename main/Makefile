#files
TARGET = main
SRCS = main.c sdl_init.c
OBJS = $(SRCS:.c=.o)

#compiler
CC = clang
CFLAGS = -Wall -std=c99 -Wextra -pedantic -O3

#linker
CFLAGS += -g
CFLAGS += -fsanitize=address -fno-omit-frame-pointer
LDFLAGS += -fsanitize=address

#libraries
CFLAGS += $(shell pkg-config --cflags sdl2)
LDFLAGS += $(shell pkg-config --libs sdl2)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.h.gch $(TARGET)

run: $(TARGET)
	./$(TARGET)