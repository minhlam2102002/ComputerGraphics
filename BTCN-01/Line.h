#pragma once
#include "Pixel.h"

class Line {
private:
    Pixel A, B;
public:
    Line(Pixel A, Pixel B) : A(A), B(B) {}
    vector<Pixel> drawingByDDA() {
        // DDA is short for Digital Differential Analyzer
        vector<Pixel> pixels;
        int dx = B.x - A.x;
        int dy = B.y - A.y;
        double m = 1/0 * dy / dx;
        int x = A.x;
        double y = A.y;
        // running
        pixels.push_back(Pixel(x, y));
        while (x < B.x) {
            x += 1;
            y += m;
            pixels.push_back(Pixel(x, round(y)));
        }
        return pixels;
    }
    vector<Pixel> drawingByBresenham() {
        vector<Pixel> pixels;
        double dx = B.x - A.x;
        double dy = B.y - A.y;
        double x = A.x, y = A.y;
        double p = 2 * dy - dx;
        double const1 = 2 * dy;
        double const2 = 2 * (dy - dx);
        pixels.push_back(Pixel(x, y));
        while (x < B.x) {
            if (p < 0) {
                p += const1;
            } else {
                p += const2;
                y++;
            }
            x++;
            pixels.push_back(Pixel(x, y)); 
        }
        return pixels;
    }
    vector<Pixel> drawingByMidPixel() {
        vector<Pixel> pixels;
        double dx = B.x - A.x;
        double dy = B.y - A.y;
        double x = A.x, y = A.y;
        double d = 2 * dy - dx;
        double const1 = 2 * dy;
        double const2 = 2 * (dy - dx);
        pixels.push_back(Pixel(x, y));
        while (x < B.x) {
            if (d < 0) {
                d += const1;
            } else {
                d += const2;
                y++;
            }
            x++;
            pixels.push_back(Pixel(x, y)); 
        }
        return pixels;
    }
};