#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int SQUARE_SIZE = 64;

int main() {


    sf::VideoMode display(600, 600);
    sf::RenderWindow window(display, "Chess", sf::Style::Close);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Draw Board
        window.clear(sf::Color::Red);
        int cur_y = 10;
        int cur_x = 10;
        int color = 1;

        for (int row = 0; row < 8 ; row++) {
            for (int column = 0; column < 8 ; column++) {
                sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));

                
                // Alternate Colors
                color == 1 ? square.setFillColor(sf::Color::Black) : square.setFillColor(sf::Color::White);
                color *= -1;
                
                square.setPosition(cur_x, cur_y);

                cur_x += SQUARE_SIZE;

                window.draw(square);
            }

            cur_y += SQUARE_SIZE;
            cur_x = 10;
            color *= -1;
        }

       
        window.display();
    }

    return EXIT_SUCCESS;
}
