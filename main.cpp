#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int main() {
    sf::VideoMode display(800, 800);
    sf::RenderWindow window(display, "Chess");

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;
}
