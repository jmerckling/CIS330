SOURCES = Battleship.c main.c
HEADERS = Battleship.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

clean:
	$(RM) main $(OBJECTS) *.o
