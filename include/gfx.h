#pragma once

#include <vector>

using namespace std;

///
/// \brief Class to define Color of a pixel in a Bitmap
///
class color{

private:
    int r, g, b;

public:

    ///
    /// \brief color Constructor for Color Class
    /// \param _r Red Component of Pixel Range(0-255)
    /// \param _g Green Component of Pixel Range(0-255)
    /// \param _b Blue Component of Pixel Range(0-255)


    color();
    color(int _r, int _g, int _b);

    ///
    /// \brief Access to red color Component of Color Class
    /// \return int Range(0-255) Red Intensity
    ///
    int get_r();

    ///
    /// \brief Access to green color Component of Color Class
    /// \return int Range(0-255) Green Intensity
    ///
    int get_g();

    ///
    /// \brief Access to blue color Component of Color Class
    /// \return int Range(0-255) Blue Intensity
    ///
    int get_b();
};

///
/// \brief 2D Array of Pixels with width and height to store image information
///
class bitmap{

private:
    int height, width;
    vector <vector <color>> data;

public:
    ///
    /// \brief bitmap Constructor of Bitmap Class
    /// \param _width Width of Image
    /// \param _height Height of Image
    ///
    bitmap(int _width, int _height);

    ///
    /// \brief Set Pixel to specific Color
    /// \param x X-Coordinate of Pixel in window
    /// \param y Y-Coordinate of Pixel in window
    /// \param col Color to set Pixel to
    /// \return Boolean wether operation was sucessful or not
    ///

    bool set_pixel(int x, int y, color col);

    ///
    /// \brief Returns Color information of a given Pixel
    /// \param x X-Coordinate of Pixel in window
    /// \param y Y-Coordinate of Pixel in window
    /// \return color Color of Pixel
    ///
    color get_pixel(int x, int y);

    ///
    /// \brief Returns Height of Bitmap
    /// \return int height
    ///
    int get_height();

    ///
    /// \brief Return Width of Bitmap
    /// \return int width
    ///
    int get_width();
};
