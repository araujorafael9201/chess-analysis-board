CC = g++
ARGS = -lsfml-graphics -lsfml-window -lsfml-system


main: main.o board.o
	$(CC) -o main main.o board.o $(ARGS)

main.o: main.cpp
	$(CC) -c main.cpp $(ARGS)

board.o: board.cpp board.h
	$(CC) -c board.cpp
