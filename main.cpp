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

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Red);
        
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

                
                cur_x += SQUARE_SIZE;
            }

            cur_y += SQUARE_SIZE;
            cur_x = 0;
            color *= -1;
        }

       
        window.display();
    }

    return EXIT_SUCCESS;
}
