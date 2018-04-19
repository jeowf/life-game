CC = g++
CPPFLAGS = -O -Wall -std=c++11
OBJS = life_game.o
HEADER_DIR  = ./include/
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

life: $(OBJS)
	$(CC) $(OBJS) -o life
	mv *.o $(BIN_DIR)

life_game.o:
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)life_game.cpp

clean:
	rm -f $(BIN_DIR)*.o lifegame *.o
