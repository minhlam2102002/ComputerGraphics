#pragma once
#include "Point.h"
#include <cmath>

class Hyperbola {
private:
    Point p;
    int a, b;
public:
    Hyperbola(vector<int> args) {
        this->p = Point(args[0], args[1]);
        this->a = args[2];
        this->b = args[3];
    }
    float eval(const float &x, const float &y) const{
        const float a2 = a * a, b2 = b * b, x2 = x * x, y2 = y * y;
        return b2 * x2 - a2 * y2 - a2 * b2;
    }
    void drawByMidPoint() {
        int x = a, y = 0; 
        const int a2 = a * a, b2 = b * b;
        int f = round(this->eval(x + 0.5, y + 1));
        int dx = 2 * b2 * x, dy = 0;

        glBegin(GL_POINTS);
        while (abs(dy) < dx && isInWindow(x, y)) {
            y++;
            dy += -2 * a2;
            if (f >= 0) {
                f += -a2 * (2 * y + 3);
            } else {
                x++;
                dx += 2 * b2;
                f += -a2 * (2 * y + 3) + b2 * (2 * x + 2);
            }
            this->p.draw4SymPoints(x, y);
        }
        f = round(this->eval(x + 1, y + 0.5));
        while (isInWindow(x, y)) {
            x++;
            if (f < 0) {
                f += b2 * (2 * x + 3);
            } else {
                y++;
                f += b2 * (2 * x + 3) - a2 * (2 * y + 2);
            }
            this->p.draw4SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
    void drawByGL() {
        glBegin(GL_POINTS);
        for (int t = -500; t <= 500; t++) {
            int x = round((float)this->a / cos(t));
            int y = round((float)this->b * tan(t));
            this->p.draw4SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
};