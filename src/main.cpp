#include <SFML/Graphics.hpp>
#include <world.h>

sf::Image parseBitmap(bitmap picture);

int main()
{
    const unsigned int W = 200;
    const unsigned int H = 200;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(W, H), "simple_raytracer");
    // Start the game loop

    vec3 camera = vec3(0, 0, -0.1);
    world welt{W, H, camera};

    int tris1 = welt.add_object(triangle(vec3(-0.2, 0, 0), vec3(0.4, 0, 0), vec3(0, 0.2, 0)));
    bitmap picture = welt.rasterize();

    sf::Texture tex;
    sf::Sprite sp;

    tex.create(W, H);

    tex.loadFromImage(parseBitmap(picture));
    sp.setTexture(tex);

    while(window.isOpen())
    {
        window.draw(sp);

        welt.manipulate_object(tris1, 1, 0.01);

        bitmap picture = welt.rasterize();
        tex.loadFromImage(parseBitmap(picture));
        sp.setTexture(tex);

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
        window.clear();
    }
    return EXIT_SUCCESS;
}

sf::Image parseBitmap(bitmap picture)
{
    sf::Image result;
    result.create(picture.get_width(), picture.get_height(), sf::Color::Black);

    for(int x = 0; x < picture.get_width(); x++)
    {
        for(int y = 0; y < picture.get_height(); y++)
        {
            color orig = picture.get_pixel(x, y);
            sf::Color col = sf::Color(orig.get_r(), orig.get_g(), orig.get_b());
            result.setPixel(x, y, col);
        }
    }

    return result;
}
