#pragma once
#include "Pixel.h"

class Circle {
private:
    Pixel p;
    double r;
public:
    Circle(Pixel p, double r) : p(p), r(r) {}
    vector<Pixel> drawingByMidPixel() {
        vector<Pixel> res;
        double x = 0, y = r;
        double d = 1 - r;
        while (x <= y) {
            res.push_back(Pixel(x, y));
            res.push_back(Pixel(x, -y));
            res.push_back(Pixel(-x, y));
            res.push_back(Pixel(-x, -y));
            res.push_back(Pixel(y, x));
            res.push_back(Pixel(y, -x));
            res.push_back(Pixel(-y, x));
            res.push_back(Pixel(-y, -x));
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