#pragma once
#include "global.h"
#include "DrawFunction.h"

class Object {
private:
public:
    Pixel start, end;
    RGBColor color;
    void (*drawFunc)(const Pixel&, const Pixel&, const RGBColor&);
    Object(const Pixel&, const Pixel&, const RGBColor&, string);
    bool isClicked(const Pixel &);
    void drawObject();
};