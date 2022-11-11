#include "DrawFunction.h"

void drawLine(const Pixel &start, const Pixel &end, const RGBColor &color) {
    glBegin(GL_LINES);
    glColor(color);
    glVertex(start);
    glVertex(end);
    glEnd();
}
// ----------------------------------------------------------------
void drawRectangle(const Pixel &start, const Pixel &end, const RGBColor &color) {
    glBegin(GL_LINE_LOOP);
    glColor(color);
    glVertex(start);
    glVertex2i(end.x, start.y);
    glVertex(end);
    glVertex2i(start.x, end.y);
    glEnd();
}
void drawSquare(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel diff = end - start;
    int side = min(abs(diff.x), abs(diff.y));
    diff.x = diff.x > 0 ? side : -side;
    diff.y = diff.y > 0 ? side : -side;
    Pixel newEnd = start + diff;
    drawRectangle(start, newEnd, color);
}
void drawCircleBase(const Pixel &start, const Pixel &end, const RGBColor &color, int perimeter) {
    Pixel diff = end - start;
    int radius = max(abs(diff.x), abs(diff.y)) / 2;
    diff.x = diff.x > 0 ? radius : -radius;
    diff.y = diff.y > 0 ? radius : -radius;

    Pixel center = start + diff;
    float angle = -M_PI_2;
    const float angleInc = 2.0 * M_PI / perimeter;

    glBegin(GL_LINE_LOOP);
    glColor(color);
    while (perimeter--) {
        diff = Pixel(radius * cos(angle), radius * sin(angle));
        glVertex(center + diff);
        angle += angleInc;
    }
    glEnd();
}
void drawCircle(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel diff = end - start;
    int radius = max(abs(diff.x), abs(diff.y)) / 2;
    int perimeter = 2.0 * M_PI * radius;
    drawCircleBase(start, end, color, perimeter);
}
void drawEllipse(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel diff = end - start;
    int a = abs(diff.x) / 2;
    int b = abs(diff.y) / 2;

    Pixel center = (start + end) / 2;
    int perimeter = M_PI * 2 * max(a, b);
    float angle = 0;
    const float angleInc = 2.0 * M_PI / perimeter;

    glBegin(GL_LINE_LOOP);
    glColor(color);
    while (perimeter--) {
        angle += angleInc;
        diff = Pixel(a * cos(angle), b * sin(angle));
        glVertex(center + diff);
    }
    glEnd();
}
void drawRightTriangle(const Pixel &start, const Pixel &end, const RGBColor &color) {
    int hypotenuse = abs(end.y - start.y);
    glBegin(GL_LINE_LOOP);
    glColor(color);
    glVertex2i((start.x + end.x) / 2, start.y);
    glEnd();
}
void drawIsoscelesTriangle(const Pixel &start, const Pixel &end, const RGBColor &color) {
    glBegin(GL_LINE_LOOP);
    glColor(color);
    glVertex2i((start.x + end.x) / 2, start.y);
    glVertex2i(start.x, end.y);
    glVertex2i(end.x, end.y);
    glEnd();
}
void drawEquilateralTriangle(const Pixel &start, const Pixel &end, const RGBColor &color) {
    int side = abs(end.x - start.x);
    if (end.y < start.y) side = -side;
    Pixel newEnd = Pixel(end.x, 1.0 * start.y + cos(M_PI / 6.0) * side);
    drawIsoscelesTriangle(start, newEnd, color);
}

void drawPentagon(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, 5);
}
void drawHexagon(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, 6);
}
void drawOctagon(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, 8);
}

void drawStar(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel diff = end - start;
    int radius = max(abs(diff.x), abs(diff.y)) / 2;
    diff.x = diff.x > 0 ? radius : -radius;
    diff.y = diff.y > 0 ? radius : -radius;

    Pixel center = start + diff;
    float angle = -M_PI_2;
    int perimeter = 8;
    const float angleInc = 2.0 * M_PI / perimeter * 5;

    glBegin(GL_LINE_LOOP);
    glColor(color);
    while (perimeter--) {
        diff = Pixel(radius * cos(angle), radius * sin(angle));
        glVertex(center + diff);
        angle += angleInc;
    }
    glEnd();
}

map<string, void (*)(const Pixel &, const Pixel &, const RGBColor &)> drawFunctions = {
    {"Line", drawLine},

    {"Right", drawRightTriangle},
    {"Isosceles", drawIsoscelesTriangle},
    {"Equilateral", drawEquilateralTriangle},

    {"Rectangle", drawRectangle},
    {"Square", drawSquare},

    {"Circle", drawCircle},
    {"Ellipse", drawEllipse},

    {"Pentagon", drawPentagon},
    {"Hexagon", drawHexagon},
    {"Octagon", drawOctagon},

    // {"Arrow", drawArrow},
    {"Star", drawStar},

    // {"Plus", drawPlus},
    // {"Minus", drawMinus},
    // {"Multiply", drawMultiply},
    // {"Divide", drawDivide},
};