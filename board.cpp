#include "board.h"
#include <iostream>
#include <string.h>

using namespace std;
void Board::show()
{
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            cout << this->pieces[x][y];
        }

        cout << endl;
    }
}

bool Board::is_move_legal(int initial_row, int initial_column, int destination_row, int destination_column)
{
    char piece = this->pieces[initial_row][initial_column];
    bool legal;

    switch (piece)
    {
    // White Pieces
    case 'P':
        legal = false;
        if (initial_row == 6)
        {
            // Hasn't moved yet
            if (destination_column == initial_column && destination_row == initial_row - 2)
            {
                if (this->pieces[initial_row - 1][initial_column] == 'X' && this->pieces[initial_row - 2][initial_column] == 'X')
                {
                    legal = true;
                }
            }
        }
        if (destination_column == initial_column && destination_row == initial_row - 1)
        {
            if (this->pieces[initial_row - 1][initial_column] == 'X')
            {
                legal = true;
            }
        }

        break;

    case 'R':
        legal = true;
        if (destination_column == initial_column && destination_row != initial_row)
        {
            if (destination_row > initial_row)
            {
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][destination_column] != 'X')
                    {
                        legal = false;
                    }
                }
            }
            else if (destination_row < initial_row)
            {
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][destination_column] != 'X')
                    {
                        legal = false;
                    }
                }
            }
        }
        else if (destination_row == initial_row && destination_column != initial_column)
        {
            if (destination_column > initial_column)
            {
                for (int column_to_check = initial_column + 1; column_to_check <= destination_column; column_to_check++)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
            else if (destination_column < initial_column)
            {
                for (int column_to_check = initial_column - 1; column_to_check >= destination_column; column_to_check--)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
        }
        else
        {
            legal = false;
        }

        break;

    case 'N':
        if (this->pieces[destination_row][destination_column] != 'X')
        {
            legal = false;
            break;
        }

        if ((destination_column == initial_column + 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row - 1) || (destination_column == initial_column + 2 && destination_row == initial_row - 1))
        {
            legal = true;
        }
        else
        {
            legal = false;
        }

        break;

    case 'B':
        legal = true;
        // Check if bishop is moving in a diagonal
        if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column))
        {
            // Check if there is a piece on the way
            if (destination_row > initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row > initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
            else if (destination_row < initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row < initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
            else
            {
                legal = false;
                break;
            }
        }
        else
        {
            legal = false;
        }

        break;

    case 'Q':
        legal = true;
        if (destination_column == initial_column)
        {
            if (destination_row != initial_row)
                if (destination_row > initial_row)
                {
                    for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                    {
                        if (this->pieces[row_to_check][destination_column] != 'X')
                        {
                            legal = false;
                        }
                    }
                }
                else if (destination_row < initial_row)
                {
                    for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                    {
                        if (this->pieces[row_to_check][destination_column] != 'X')
                        {
                            legal = false;
                        }
                    }
                }
        }
        else if (destination_row == initial_row)
        {
            if (destination_column > initial_column)
            {
                for (int column_to_check = initial_column + 1; column_to_check <= destination_column; column_to_check++)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
            else if (destination_column < initial_column)
            {
                for (int column_to_check = initial_column - 1; column_to_check >= destination_column; column_to_check--)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
        }
        else if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column))
        {
            // Check if there is a piece on the way
            if (destination_row > initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row > initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
            else if (destination_row < initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row < initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
        }
        else
        {
            legal = false;
        }
        break;
    case 'K':
        if (this->pieces[destination_row][destination_column] != 'X')
        {
            legal = false;
            break;
        }
        if (destination_column == initial_column)
        {
            if (destination_row - initial_row == 1 || destination_row - initial_row == -1)
            {
                legal = true;
            }
            else
            {
                legal = false;
            }
        }
        else if (destination_row == initial_row)
        {
            if (destination_column - initial_column == 1 || destination_column - initial_column == -1)
            {
                legal = true;
            }
            else
            {
                legal = false;
            }
        }
        else
        {
            if ((destination_column - initial_column) * (destination_column - initial_column) == 1 && (destination_row - initial_row) * (destination_row - initial_row) == 1)
            {
                legal = true;
            }
            else
            {
                legal = false;
            }
        }

        break;

    // Black Pieces
    case 'p':
        legal = false;
        if (initial_row == 1)
        {
            // Hasn't moved yet
            if (destination_column == initial_column && destination_row == initial_row + 2)
            {
                if (this->pieces[initial_row + 1][initial_column] == 'X' && this->pieces[initial_row + 2][initial_column] == 'X')
                {
                    legal = true;
                }
            }
        }
        if (destination_column == initial_column && destination_row == initial_row + 1)
        {
            if (this->pieces[initial_row + 1][initial_column] == 'X')
            {
                legal = true;
            }
        }

        break;

    case 'r':
        legal = true;
        if (destination_column == initial_column && destination_row != initial_row)
        {
            if (destination_row > initial_row)
            {
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][destination_column] != 'X')
                    {
                        legal = false;
                    }
                }
            }
            else if (destination_row < initial_row)
            {
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][destination_column] != 'X')
                    {
                        legal = false;
                    }
                }
            }
        }
        else if (destination_row == initial_row && destination_column != initial_column)
        {
            if (destination_column > initial_column)
            {
                for (int column_to_check = initial_column + 1; column_to_check <= destination_column; column_to_check++)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
            else if (destination_column < initial_column)
            {
                for (int column_to_check = initial_column - 1; column_to_check >= destination_column; column_to_check--)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
        }
        else
        {
            legal = false;
        }

        break;

    case 'n':
        if (this->pieces[destination_row][destination_column] != 'X')
        {
            legal = false;
            break;
        }
        if ((destination_column == initial_column + 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row + 2) || (destination_column == initial_column - 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 1 && destination_row == initial_row - 2) || (destination_column == initial_column + 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row + 1) || (destination_column == initial_column - 2 && destination_row == initial_row - 1) || (destination_column == initial_column + 2 && destination_row == initial_row - 1))
        {
            legal = true;
        }
        else
        {
            legal = false;
        }

        break;

    case 'b':
        legal = true;
        // Check if bishop is moving in a diagonal
        if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column))
        {
            // Check if there is a piece on the way
            if (destination_row > initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row > initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
            else if (destination_row < initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row < initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
            else
            {
                legal = false;
                break;
            }
        }
        else
        {
            legal = false;
        }

        break;
    case 'q':
        legal = true;
        if (destination_column == initial_column)
        {
            if (destination_row != initial_row)
                if (destination_row > initial_row)
                {
                    for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                    {
                        if (this->pieces[row_to_check][destination_column] != 'X')
                        {
                            legal = false;
                        }
                    }
                }
                else if (destination_row < initial_row)
                {
                    for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                    {
                        if (this->pieces[row_to_check][destination_column] != 'X')
                        {
                            legal = false;
                        }
                    }
                }
        }
        else if (destination_row == initial_row)
        {
            if (destination_column > initial_column)
            {
                for (int column_to_check = initial_column + 1; column_to_check <= destination_column; column_to_check++)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
            else if (destination_column < initial_column)
            {
                for (int column_to_check = initial_column - 1; column_to_check >= destination_column; column_to_check--)
                {
                    if (this->pieces[destination_row][column_to_check] != 'X')
                    {
                        legal = false;
                    }
                }
            }
        }
        else if ((destination_row - initial_row) * (destination_row - initial_row) == (destination_column - initial_column) * (destination_column - initial_column))
        {
            // Check if there is a piece on the way
            if (destination_row > initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row > initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row + 1; row_to_check <= destination_row; row_to_check++)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
            else if (destination_row < initial_row && destination_column > initial_column)
            {
                int column_to_check = initial_column + 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check++;
                }
            }
            else if (destination_row < initial_row && destination_column < initial_column)
            {
                int column_to_check = initial_column - 1;
                for (int row_to_check = initial_row - 1; row_to_check >= destination_row; row_to_check--)
                {
                    if (this->pieces[row_to_check][column_to_check] != 'X')
                    {
                        legal = false;
                        break;
                    }
                    column_to_check--;
                }
            }
        }
        else
        {
            legal = false;
        }
        break;

    case 'k':
        if (this->pieces[destination_row][destination_column] != 'X')
        {
            legal = false;
            break;
        }
        if (destination_column == initial_column)
        {
            if (destination_row - initial_row == 1 || destination_row - initial_row == -1)
            {
                legal = true;
            }
            else
            {
                legal = false;
            }
        }
        else if (destination_row == initial_row)
        {
            if (destination_column - initial_column == 1 || destination_column - initial_column == -1)
            {
                legal = true;
            }
            else
            {
                legal = false;
            }
        }
        else
        {
            if ((destination_column - initial_column) * (destination_column - initial_column) == 1 && (destination_row - initial_row) * (destination_row - initial_row) == 1)
            {
                legal = true;
            }
            else
            {
                legal = false;
            }
        }

        break;
    }

    return legal;
}

Board::Board(string pos)
{
    int index_x = 0;
    int index_y = 0;

    for (char p : pos)
    {
        if (p == '/')
        {
            // If it is a '/', jump a row
            index_y++;
            index_x = 0;
        }
        else if (isalpha(p))
        {
            // If it is a letter, put the letter in place
            this->pieces[index_y][index_x] = p;
            index_x++;
        }
        else if (isdigit(p))
        {
            // If it is a number "x", put x blank spaces in the row
            int blanks = p - '0';
            for (int c = 0; c < blanks; c++)
            {
                this->pieces[index_y][index_x] = 'X';
                index_x++;
            }
        }
    }

    this->show();
}

void Board::move(char piece, int initial_row, int initial_column, int destination_row, int destination_column)
{

    this->pieces[destination_row][destination_column] = piece;
    this->pieces[initial_row][initial_column] = 'X';

    this->show();
    return;
}
