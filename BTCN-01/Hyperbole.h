#pragma once
#include "Pixel.h"

class Hyperbole : Pixel {
private:
    double a, b;
    Pixel p;
public:
    Hyperbole(double x = 0, double y = 0, double a = 0, double b = 0) : Pixel(x, y), a(a), b(b) {}
    Hyperbole(Pixel p, double a, double b) : Pixel(p), a(a), b(b) {}
    vector<Pixel> displayMidPixel() {
        vector<Pixel> res;
        double x = 0, y = b;
        double d1 = b * b - a * a * b + a * a / 4;
        while (b * b * x <= a * a * y) {
            res.push_back(Pixel(x, y));
            res.push_back(Pixel(x, -y));
            res.push_back(Pixel(-x, y));
            res.push_back(Pixel(-x, -y));
            if (d1 < 0) {
                d1 += b * b * (2 * x + 3);
            } else {
                d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
                y--;
            }
            x++;
        }
        double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
        while (y >= 0) {
            res.push_back(Pixel(x, y));
            res.push_back(Pixel(x, -y));
            res.push_back(Pixel(-x, y));
            res.push_back(Pixel(-x, -y));
            if (d2 < 0) {
                d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
                x++;
            } else {
                d2 += a * a * (-2 * y + 3);
            }
            y--;
        }
        return res;
    }
};