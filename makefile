CC = g++
CPPFLAGS = -O -Wall -std=c++11
OBJS = main.o dice.o game.o player.o
HEADER_DIR  = ./include/
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

lifegame: $(OBJS)
	$(CC) $(OBJS) -o lifegame
	mv *.o $(BIN_DIR)

clean:
	rm -f $(BIN_DIR)*.o lifegame *.o
