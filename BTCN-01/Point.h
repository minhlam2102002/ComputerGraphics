#pragma once
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

class Point;
class Line;
class Circle;
class Ellipse;
class Hyperbole;

class Point {
private:
    int x, y;
    friend class Line;
    friend class Circle;
    friend class Ellipse;
    friend class Hyperbole;
public:
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
