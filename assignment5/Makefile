SOURCES = game.cpp main.cpp
HEADERS = game.hpp 
OBJECTS = $(SOURCES:.cpp=.o)
LIBS = -lm

CC = g++
CFLAGS = -g -std=c++11

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

clean: 
	$(RM) main $(OBJECTS) *.o
