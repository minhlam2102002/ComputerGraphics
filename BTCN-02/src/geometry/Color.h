#pragma once
#include "../library.h"
class RGBColor {
public:
    float r, g, b;
    RGBColor(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    RGBColor(float pixel[3]) {
        this->r = pixel[0];
        this->g = pixel[1];
        this->b = pixel[2];
    }
    void set() {
        glColor3f(r, g, b);
    }
};