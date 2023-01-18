CC = g++
ARGS = -lsfml-graphics -lsfml-window -lsfml-system

main: main.o
	$(CC) -o main main.o -lsfml-graphics $(ARGS)

main.o: main.cpp
	$(CC) -c main.cpp $(ARGS) 

