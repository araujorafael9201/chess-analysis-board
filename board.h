#ifndef BOARD_H
#define BOARD_H

#include <string.h>
#include <iostream>

using namespace std;

class Board {
    public:
        Board(string pos);
        void move(char piece, int initial_row, int initial_column, int destination_row, int destination_column);
        void show();

        char pieces[8][8];
};

#endif
