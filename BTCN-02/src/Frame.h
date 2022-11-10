#pragma once
#include "global.h"

class Frame {
private:
    int width, height;
    float *frame;

private:
    int indexOf(Pixel);
    void boundaryFill(Pixel, RGBColor, RGBColor);
    void floodFill(Pixel, RGBColor, RGBColor);

public:
    Frame();
    Frame(int, int);
    bool possess(Pixel);
    void setPixelColor(Pixel, RGBColor);
    RGBColor getPixelColor(Pixel);
    void display();
    void capture();
    void fill(Pixel, RGBColor);
};