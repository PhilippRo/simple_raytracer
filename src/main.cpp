#include <SFML/Graphics.hpp>
#include <world.h>

int main()
{
    const unsigned int W = 800;
    const unsigned int H = 600;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(W, H), "simple_raytracer");
    // Start the game loop

    vec3 camera = vec3(0, 0, -1);
    world welt{W, H, camera};

    welt.add_object(triangle(vec3(0, 0, 0), vec3(3, 0, 0), vec3(1, 1, 0)));
    bitmap picture = welt.rasterize();

    sf::Image result;
    sf::Texture tex;
    sf::Sprite sp;

    result.create(W, H, sf::Color::Blue);
    tex.create(W, H);

    for(int x = 0; x < W; x++)
    {
        for(int y = 0; y < H; y++)
        {
            color orig = picture.get_pixel(x, y);
            sf::Color col = sf::Color(orig.get_r(), orig.get_g(), orig.get_b());
            result.setPixel(x, y, col);
        }
    }

    tex.loadFromImage(result);
    sp.setTexture(tex);

    while (window.isOpen())
    {
        window.draw(sp);
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
