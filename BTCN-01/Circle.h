#pragma once
#include "Point.h"

class Circle {
private:
    Point p;
    double r;
public:
    Circle(Point p, double r) {
        this->p = p;
        this->r = r;
    }
    Circle(vector<int> coords) {
        this->p = Point(coords[0], coords[1]);
        this->r = coords[2];
    }
    vector<Point> drawByMidPoint() {
        vector<Point> res;
        double x = 0, y = r;
        double d = 1 - r;
        while (x <= y) {
            res.push_back(Point(x, y));
            res.push_back(Point(x, -y));
            res.push_back(Point(-x, y));
            res.push_back(Point(-x, -y));
            res.push_back(Point(y, x));
            res.push_back(Point(y, -x));
            res.push_back(Point(-y, x));
            res.push_back(Point(-y, -x));
            if (d < 0) {
                d += 2 * x + 3;
            } else {
                d += 2 * (x - y) + 5;
                y--;
            }
            x++;
        }
        return res;
    }
};