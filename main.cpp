#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "board.h"

using namespace std;

int SQUARE_SIZE = 64;

int main() {


    sf::VideoMode display(512, 512);
    sf::RenderWindow window(display, "Chess", sf::Style::Close);


    // Create board
    Board board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

    // Load pieces sprite
    sf::Texture texture;
    texture.loadFromFile("./sprites/pieces.png");
    texture.setSmooth(true);

    sf::Sprite piece;
    piece.setTexture(texture);
    piece.setScale(0.2f, 0.2f);

    sf::Sprite dragged_piece;
    dragged_piece.setTexture(texture);
    dragged_piece.setScale(0.2f, 0.2f);
    dragged_piece.setTextureRect(sf::IntRect(0, 0, 0, 0));

    // This variable controls the mouse action when clicking the screen to move
    bool is_moving = false;

    // Mouse coordinates variables
    int initial_row;
    int initial_column;
    int destination_row;
    int destination_column;

    char piece_to_move;
    
    int piece_being_dragged_x;
    int piece_being_dragged_y;

    bool dragging;
        
    while (window.isOpen()) {
        sf::Event e;
        window.clear(sf::Color::Red);
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            } else if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {
                // If mouse is clicked
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);


                if (mouse_position.x >= 0 && mouse_position.y >= 0 && mouse_position.x <= 512 && mouse_position.y <= 512) {
                    if (!is_moving) {
                        // Get position where mouse was clicked
                        initial_row = mouse_position.y / 64;
                        initial_column = mouse_position.x / 64;
                        piece_to_move = board.pieces[initial_row][initial_column];
                
                        // User can't move blank spaces
                        piece_to_move != 'X' ? is_moving = true : is_moving = false;
                    } else {
                        // If a piece has been selected, move it to the place where mouse was clicked the second time
                        destination_row = mouse_position.y / 64;
                        destination_column = mouse_position.x / 64;

                        if (board.is_move_legal(initial_row, initial_column, destination_row, destination_column)) {
                            board.move(piece_to_move, initial_row, initial_column, destination_row, destination_column);
                        }


                        is_moving = false;
                    }

            }


        } else if (e.type == sf::Event::MouseButtonReleased) {
                dragging = false;

                // Stop drawing the piece that follows the mouse
                dragged_piece.setTextureRect(sf::IntRect(0, 0, 0, 0));

                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                destination_row = mouse_position.y / 64;
                destination_column = mouse_position.x / 64;
                            
                if (destination_row == initial_row && destination_column == initial_column) {
                    // If mouse is released in the same place, user can move by clicking again
                    continue;
                } else {
                    // If mouse is released in a diferent place, the piece moves there
                    if (board.is_move_legal(initial_row, initial_column, destination_row, destination_column)) {
                            board.move(piece_to_move, initial_row, initial_column, destination_row, destination_column);
                        }
                    is_moving = false;
                }

        }

        }

        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

            int row = mouse_position.y / 64;
            int column = mouse_position.x / 64;

            // While mouse is being pressed, make the selected piece follow it

            // Load correct piece sprite, but only when the mouse if first clicked
            if (!dragging) {


            switch (board.pieces[row][column]) {
                    case 'p':
                        dragged_piece.setTextureRect(sf::IntRect(1600, 320, 320, 320));
                        break;
                    case 'r': 
                        dragged_piece.setTextureRect(sf::IntRect(1280, 320, 320, 320));
                        break;
                    case 'n':
                        dragged_piece.setTextureRect(sf::IntRect(960, 320, 320, 320));
                        break;
                    case 'b':
                        dragged_piece.setTextureRect(sf::IntRect(640, 320, 320, 320));
                        break;
                    case 'q':
                        dragged_piece.setTextureRect(sf::IntRect(320, 320, 320, 320));
                        break;
                    case 'k':
                        dragged_piece.setTextureRect(sf::IntRect(0, 320, 320, 320));
                        break;
                    case 'P':
                        dragged_piece.setTextureRect(sf::IntRect(1600, 0, 320, 320));
                        break;
                    case 'R': 
                        dragged_piece.setTextureRect(sf::IntRect(1280, 0, 320, 320));
                        break;
                    case 'N':
                        dragged_piece.setTextureRect(sf::IntRect(960, 0, 320, 320));
                        break;
                    case 'B':
                        dragged_piece.setTextureRect(sf::IntRect(640, 0, 320, 320));
                        break;
                    case 'Q':
                        dragged_piece.setTextureRect(sf::IntRect(320, 0, 320, 320));
                        break;
                    case 'K':
                        dragged_piece.setTextureRect(sf::IntRect(0, 0, 320, 320));
                        break;
                    case 'X':
                        dragged_piece.setTextureRect(sf::IntRect(0, 0, 0, 0));
                        break;
            }
                piece_being_dragged_x = row;
                piece_being_dragged_y = column;
            }

            

            dragging = true;
            dragged_piece.setPosition(mouse_position.x, mouse_position.y);
        }


       
        // Draw Board
        int cur_y = 0;
        int cur_x = 0;
        int color = -1;

        
        for (int row = 0; row < 8 ; row++) {
            for (int column = 0; column < 8 ; column++) {
                // Create square
                sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));

                // Alternate Colors
                color == 1 ? square.setFillColor(sf::Color::Blue) : square.setFillColor(sf::Color::White);
                color *= -1;
                
                // Put square in place
                square.setPosition(cur_y, cur_x);


                
                // Draw Square
                window.draw(square);
                
                // If a piece is being dragged, do not draw it
                if (!(dragging && column == piece_being_dragged_x && row == piece_being_dragged_y)) {



                // Load correct piece sprite
                switch (board.pieces[column][row]) {
                    case 'p':
                        piece.setTextureRect(sf::IntRect(1600, 320, 320, 320));
                        break;
                    case 'r': 
                        piece.setTextureRect(sf::IntRect(1280, 320, 320, 320));
                        break;
                    case 'n':
                        piece.setTextureRect(sf::IntRect(960, 320, 320, 320));
                        break;
                    case 'b':
                        piece.setTextureRect(sf::IntRect(640, 320, 320, 320));
                        break;
                    case 'q':
                        piece.setTextureRect(sf::IntRect(320, 320, 320, 320));
                        break;
                    case 'k':
                        piece.setTextureRect(sf::IntRect(0, 320, 320, 320));
                        break;
                    case 'P':
                        piece.setTextureRect(sf::IntRect(1600, 0, 320, 320));
                        break;
                    case 'R': 
                        piece.setTextureRect(sf::IntRect(1280, 0, 320, 320));
                        break;
                    case 'N':
                        piece.setTextureRect(sf::IntRect(960, 0, 320, 320));
                        break;
                    case 'B':
                        piece.setTextureRect(sf::IntRect(640, 0, 320, 320));
                        break;
                    case 'Q':
                        piece.setTextureRect(sf::IntRect(320, 0, 320, 320));
                        break;
                    case 'K':
                        piece.setTextureRect(sf::IntRect(0, 0, 320, 320));
                        break;
                    case 'X':
                        piece.setTextureRect(sf::IntRect(0, 0, 0, 0));
                        break;
                }


                // Draw piece
                piece.setPosition(cur_y, cur_x);
                
                window.draw(piece);
                
                }
                cur_x += SQUARE_SIZE;
            }

            cur_y += SQUARE_SIZE;
            cur_x = 0;
            color *= -1;
        }


        window.draw(dragged_piece);


        window.display();
    }

    return EXIT_SUCCESS;
}
