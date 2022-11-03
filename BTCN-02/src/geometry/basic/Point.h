#pragma once
#include "../../library.h"
#include "../GeometryObject.h"
#include "../Color.h"
class Line;
class Circle;
class Ellipse;
class Hyperbola;
class Parabola;

class Point {
private:
    int x, y;
    RGBColor *color = nullptr;
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    friend class Line;
    friend class Circle;
    friend class Ellipse;
    friend class Parabola;
    friend class Hyperbola;
public:
    Point() {
        this->x = 0;
        this->y = 0;
        this->color = nullptr;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        this->color = nullptr;
    }

    Point(int x, int y, RGBAColor* color) {
        this->x = x;
        this->y = y;
        this->color = color;
    }
    void setColor() {
        if (this->color != nullptr)
            color->set();
    }
    void setVertex(int layer = 0) {
        glVertex2i(this->x, this->y);
    }
    void draw2SymPoints(int x, int y) { // symmetric on y-axis
        glVertex2i(this->x + x, this->y + y);
        glVertex2i(this->x - x, this->y + y);
    }
    void render4SymPoints(int x, int y) { // symmetric on x-axis and y-axis
        for (int i = 0; i < 4; i++) 
            glVertex2i(this->x + x * dx[i], this->y + y * dy[i]);
    }
    void draw8SymPoints(int x, int y) { // symmetric on x-axis, y-axis and origin
        for (int i = 0; i < 4; i++) {
            glVertex2i(this->x + x * dx[i], this->y + y * dy[i]);
            glVertex2i(this->x + y * dx[i], this->y + x * dy[i]);
        }
    }
};
