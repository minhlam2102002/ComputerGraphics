#include "global.h"

class Canvas {
private:
    int width, height;
    float* frame;
public:
    Canvas();
public:
    bool contain(const Pixel&);
    int indexOf(const Pixel&);
    void setPixelColor(const Pixel&, const RGBColor&);
    RGBColor getPixelColor(const Pixel&);
public:
    void clear();
    void render();
    void capture();
public:
    void floodFill(const Pixel&, const RGBColor&, const RGBColor&);
    void boundaryFill(const Pixel&, const RGBColor&, const RGBColor&);
    void scanLineFill(const Pixel&, const RGBColor&, const RGBColor&);
};