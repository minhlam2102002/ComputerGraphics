#pragma once
#include "library.h"

struct Point {
    int x, y;
    Point();
    Point(int x, int y);
    void vertex();
};

struct RGBColor {
    float r, g, b;
    RGBColor();
    RGBColor(float r, float g, float b);
    RGBColor(float pixel[3]);
    void set();
};
