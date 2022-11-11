#include "global.h"

void drawLine(const Pixel&, const Pixel&, const RGBColor&);

void drawRightTriangle(const Pixel&, const Pixel&, const RGBColor&);
void drawIsoscelesTriangle(const Pixel&, const Pixel&, const RGBColor&);
void drawEquilateralTriangle(const Pixel&, const Pixel&, const RGBColor&);

void drawRectangle(const Pixel&, const Pixel&, const RGBColor&);
void drawSquare(const Pixel&, const Pixel&, const RGBColor&);

void drawCircle(const Pixel&, const Pixel&, const RGBColor&);
void drawEllipse(const Pixel&, const Pixel&, const RGBColor&);

void drawPentagon(const Pixel&, const Pixel&, const RGBColor&);
void drawHexagon(const Pixel&, const Pixel&, const RGBColor&);
void drawOctagon(const Pixel&, const Pixel&, const RGBColor&);

// void drawArrow(const Pixel&, const Pixel&, const RGBColor&);
void drawStar(const Pixel&, const Pixel&, const RGBColor&);

// void drawPlus(const Pixel&, const Pixel&, const RGBColor&);
// void drawMinus(const Pixel&, const Pixel&, const RGBColor&);
// void drawMultiply(const Pixel&, const Pixel&, const RGBColor&);
// void drawDivide(const Pixel&, const Pixel&, const RGBColor&);

extern map<string, void (*)(const Pixel&, const Pixel&, const RGBColor&)> drawFunctions;