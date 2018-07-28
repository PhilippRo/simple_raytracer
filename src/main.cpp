#include <console.h>
#include <SFML/Graphics.hpp>
#include <vector.h>

using namespace math::vector;

const unsigned int W = 800;
const unsigned int H = 600;

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(W, H), "simple_raytracer");
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
