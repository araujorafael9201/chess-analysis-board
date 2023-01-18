#ifndef BOARD_H
#define BOARD_H

#include <string.h>
#include <iostream>

using namespace std;

class Board {
    public:
        Board(string pos);
        
        char pieces[8][8];
};

#endif
