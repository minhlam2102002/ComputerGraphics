#include "DrawFunction.h"

void drawLine(const Pixel &start, const Pixel &end, const RGBColor &color) {
    glBegin(GL_LINES);
    glColor(color);
    glVertex(start);
    glVertex(end);
    glEnd();
}
// ----------------------------------------------------------------
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
// ----------------------------------------------------------------
vector<Pixel> getRectangle(const Pixel &start, const Pixel &end) {
    return {
        Pixel(start.x, start.y), // top left
        Pixel(end.x, start.y), // top right
        Pixel(end.x, end.y), // bot right
        Pixel(start.x, end.y) // bot left
    };
}
void drawRectangle(const Pixel &start, const Pixel &end, const RGBColor &color) {
    glBegin(GL_LINE_LOOP);
    glColor(color);
    for (const Pixel& p : getRectangle(start, end))
        glVertex(p);
    glEnd();
}
void drawSquare(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel diff = end - start;
    int side = max(abs(diff.x), abs(diff.y));
    diff.x = diff.x > 0 ? side : -side;
    diff.y = diff.y > 0 ? side : -side;
    Pixel newEnd = start + diff;
    drawRectangle(start, newEnd, color);
}
// ----------------------------------------------------------------
void drawCircleBase(const Pixel &start, const Pixel &end, const RGBColor &color, bool isEllipse = false, int perimeter = 0, const int m = 1) {
    Pixel diff = end - start;

    const int a = abs(diff.x) / 2;
    const int b = abs(diff.y) / 2;

    const int radius = max(abs(diff.x), abs(diff.y)) / 2;

    if (isEllipse) {
        diff /= 2;
    } else {
        diff.x = diff.x > 0 ? radius : -radius;
        diff.y = diff.y > 0 ? radius : -radius;
    }

    if (perimeter == 0) {
        if (isEllipse) {
            perimeter = 2 * M_PI * sqrt((a * a + b * b) / 2.0);
        } else {
            perimeter = 2 * M_PI * radius;
        }
    }

    Pixel center = start + diff;
    float angle = -M_PI_2;
    const float angleInc = 2.0 * M_PI / perimeter * m;

    glBegin(GL_LINE_LOOP);
    glColor(color);
    while (perimeter--) {
        if (isEllipse) {
            diff = Pixel(a * cos(angle), b * sin(angle));
        } else {
            diff = Pixel(radius * cos(angle), radius * sin(angle));
        }
        glVertex(center + diff);
        angle += angleInc;
    }
    glEnd();
}
void drawCircle(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color);
}
void drawEllipse(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, true);
}
// ----------------------------------------------------------------
void drawPentagon(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, false, 5);
}
void drawHexagon(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, false, 6);
}
void drawOctagon(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, false, 8);
}
// ----------------------------------------------------------------
void drawArrow(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel topLeft = start;
    Pixel botLeft = Pixel(start.x, end.y);
    Pixel topRight = Pixel(end.x, start.y);
    Pixel botRight = end;

    Pixel moveRight = topRight - topLeft;
    Pixel moveLeft = topLeft - topRight;
    Pixel moveDown = botLeft - topLeft;
    Pixel moveUp = topLeft - botLeft;

    const int heightRatio = 3;
    const int widthRatio = 5;

    glBegin(GL_LINE_LOOP);
    glColor(color);
    Pixel p = topLeft;
    p += moveDown / heightRatio;
    glVertex(p);
    p += moveDown / heightRatio;
    glVertex(p);
    p += moveRight / widthRatio * (widthRatio - 1);
    glVertex(p);
    p += moveDown / heightRatio;
    glVertex(p);
    glVertex((botRight + topRight) / 2);
    p += moveUp;
    glVertex(p);
    p += moveDown / heightRatio;
    glVertex(p);
    glEnd();
}
void drawStar(const Pixel &start, const Pixel &end, const RGBColor &color) {
    drawCircleBase(start, end, color, false, 5, 3);
}
// ----------------------------------------------------------------
void drawPlus(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel topLeft = start;
    Pixel botLeft = Pixel(start.x, end.y);
    Pixel topRight = Pixel(end.x, start.y);
    Pixel botRight = end;

    Pixel moveRight = topRight - topLeft;
    Pixel moveLeft = topLeft - topRight;
    Pixel moveDown = botLeft - topLeft;
    Pixel moveUp = topLeft - botLeft;

    const int ratio = 5;

    glBegin(GL_LINE_LOOP);
    glColor(color);
    Pixel p = topLeft;
    p += moveRight / ratio * (ratio / 2);
    glVertex(p);
    p += moveRight / ratio;
    glVertex(p);
    p += moveDown / ratio * (ratio / 2);
    glVertex(p);
    p += moveRight / ratio * (ratio / 2);
    glVertex(p);
    p += moveDown / ratio;
    glVertex(p);
    p += moveLeft / ratio * (ratio / 2);
    glVertex(p);
    p += moveDown / ratio * (ratio / 2);
    glVertex(p);
    p += moveLeft / ratio;
    glVertex(p);
    p += moveUp / ratio * (ratio / 2);
    glVertex(p);
    p += moveLeft / ratio * (ratio / 2);
    glVertex(p);
    p += moveUp / ratio;
    glVertex(p);
    p += moveRight / ratio * (ratio / 2);
    glVertex(p);
    glEnd();
}
void drawMinus(const Pixel &start, const Pixel &end, const RGBColor &color) {
    Pixel topLeft = start;
    Pixel botLeft = Pixel(start.x, end.y);
    Pixel topRight = Pixel(end.x, start.y);
    Pixel botRight = end;

    const int ratio = 5;

    Pixel p1 = topLeft + (botLeft - topLeft) / ratio * (ratio / 2);
    Pixel p2 = topRight + (botRight - topRight) / ratio * (ratio / 2 + 1);
    drawRectangle(p1, p2, color);
}
// ----------------------------------------------------------------
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

    {"Arrow", drawArrow},
    {"Star", drawStar},

    {"Plus", drawPlus},
    {"Minus", drawMinus},
    // {"Multiply", drawMultiply},
    // {"Divide", drawDivide},
};