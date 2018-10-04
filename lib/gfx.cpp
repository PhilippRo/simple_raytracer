#include <gfx.h>

using namespace std;

color::color()
{
    r = 0;
    g = 0;
    b = 0;
}

color::color(int _r, int _g, int _b)
{
    r = _r;
    g = _g;
    b = _b;
}

int color::get_r()
{
    return r;
}

int color::get_g()
{
    return g;
}

int color::get_b()
{
    return b;
}


bitmap::bitmap(int _width, int _height)
{
    height = _height;
    width = _width;

    for(int i = 0; i < width; i++)
    {
        vector <color> temp;

        for(int j = 0; j < height; j++)
        {
            temp.push_back(color(0, 0, 0));
        }
        data.push_back(temp);
    }
}

bool bitmap::set_pixel(int x, int y, color col)
{
    data.at(x).at(y) = col;
    return true;
}

color bitmap::get_pixel(int x, int y)
{
    return data.at(x).at(y);
}

int bitmap::get_height()
{
    return height;
}

int bitmap::get_width()
{
    return width;
}
