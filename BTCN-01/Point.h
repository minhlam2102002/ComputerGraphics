#pragma once
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

class Point;
class Line;
class Circle;
class Ellipse;
class Hyperbola;
class Parabola;

class Point {
private:
    int x, y;
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};
    friend class Line;
    friend class Circle;
    friend class Ellipse;
    friend class Parabola;
    friend class Hyperbola;
public:
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void draw2SymPoints(int x, int y) { // symmetric on y-axis
        glVertex2i(this->x + x, this->y + y);
        glVertex2i(this->x - x, this->y + y);
    }
    void draw4SymPoints(int x, int y) {
        for (int i = 0; i < 4; i++) 
            glVertex2i(this->x + x * dx[i], this->y + y * dy[i]);
    }
    void draw8SymPoints(int x, int y) {
        for (int i = 0; i < 4; i++) {
            glVertex2i(this->x + x * dx[i], this->y + y * dy[i]);
            glVertex2i(this->x + y * dx[i], this->y + x * dy[i]);
        }
    }
};
