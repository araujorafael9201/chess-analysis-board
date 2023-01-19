#include "board.h"
#include <iostream>
#include <string.h>

using namespace std;
void Board::show() {
    for (int x = 0 ; x < 8 ; x++) {
        for (int y = 0; y < 8 ; y++) {
            cout << this->pieces[x][y];
        }

        cout << endl;
    }
}

bool Board::is_move_legal(int initial_row, int initial_column, int destination_row, int destination_column) {
    char piece = this->pieces[initial_row][initial_column];
    bool legal;

    switch (piece) {
        // White Pieces
        case 'P':
            if (destination_column == initial_column && destination_row == initial_row - 1) {
                legal = true;
            } else {
                legal = false;
            }

            break;

        case 'R':
            if (destination_column == initial_column) {
                if (destination_row != initial_row) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else if (destination_row == initial_row) {
                if (destination_column != initial_column) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                legal = false;
            }

            break;

        case 'N':
            if ((destination_column == initial_column + 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row - 1) || (destination_column == initial_column + 2 && destination_row == initial_row - 1)) {
                legal = true;
            } else {
                legal = false;
            }

            break;

        case 'B':
            if (destination_row != initial_row && destination_column != initial_column) {
                if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column)) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                legal = false;
            }

            break;

        case 'Q':
            if (destination_column == initial_column) {
                if (destination_row != initial_row) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else if (destination_row == initial_row) {
                if (destination_column != initial_column) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                 if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column)) {
                    legal = true;
                } else {
                    legal = false;
                }

            }

            break;

        case 'K':
            if (destination_column == initial_column) {
                if (destination_row - initial_row == 1 || destination_row - initial_row == -1) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else if (destination_row == initial_row) {
                if (destination_column - initial_column == 1 || destination_column - initial_column == -1) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                if ((destination_column - initial_column) * (destination_column - initial_column) == 1 && (destination_row - initial_row) * (destination_row - initial_row) == 1) {
                    legal = true;
                } else {
                    legal = false;
                }

            }

            break;

        // Black Pieces
        case 'p':
            if (destination_column == initial_column && destination_row == initial_row + 1) {
                legal = true;
            } else {
                legal = false;
            }

            break;

        case 'r':
            if (destination_column == initial_column) {
                if (destination_row != initial_row) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else if (destination_row == initial_row) {
                if (destination_column != initial_column) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                legal = false;
            }

            break;

        case 'n':
            if ((destination_column == initial_column + 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row - 1) || (destination_column == initial_column + 2 && destination_row == initial_row - 1)) {
                legal = true;
            } else {
                legal = false;
            }

            break;

        case 'b':
            if (destination_row != initial_row && destination_column != initial_column) {
                if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column)) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                legal = false;
            }

            break;

        case 'q':
            if (destination_column == initial_column) {
                if (destination_row != initial_row) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else if (destination_row == initial_row) {
                if (destination_column != initial_column) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                 if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column)) {
                    legal = true;
                } else {
                    legal = false;
                }

            }

            break;

        case 'k':
            if (destination_column == initial_column) {
                if (destination_row - initial_row == 1 || destination_row - initial_row == -1) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else if (destination_row == initial_row) {
                if (destination_column - initial_column == 1 || destination_column - initial_column == -1) {
                    legal = true;
                } else {
                    legal = false;
                }
            } else {
                if ((destination_column - initial_column) * (destination_column - initial_column) == 1 && (destination_row - initial_row) * (destination_row - initial_row) == 1) {
                    legal = true;
                } else {
                    legal = false;
                }

            }

            break;

        }


    return legal;
}

Board::Board(string pos) {
    int index_x = 0;
    int index_y = 0;

    for (char p : pos) {
        if (p == '/') {
            // If it is a '/', jump a row
            index_y++;
            index_x = 0;
        } else if (isalpha(p)) {
            // If it is a letter, put the letter in place
            this->pieces[index_y][index_x] = p;
            index_x++;
        } else if (isdigit(p)) {
            // If it is a number "x", put x blank spaces in the row
            int blanks = p - '0';
            for (int c = 0; c < blanks ; c++) {
                this->pieces[index_y][index_x] = 'X';
                index_x++;
            }
        }
    }

    
    this->show();

}

void Board::move(char piece, int initial_row, int initial_column, int destination_row, int destination_column) {


    this->pieces[destination_row][destination_column] = piece;
    this->pieces[initial_row][initial_column] = 'X';

    return;
}
