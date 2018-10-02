#pragma once

#include <vector>

using namespace std;

class color{

private:
    int r, g, b;

public:
    color(int _r, int _g, int _b);
    int get_r();
    int get_g();
    int get_b();
};

class bitmap{

private:
    vector <vector <color>> data;

public:

    bitmap(int height, int width);

    bool set_pixel(int x, int y, color col);
    color get_pixel(int x, int y);
};
