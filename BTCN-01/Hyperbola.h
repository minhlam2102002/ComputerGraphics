#pragma once
#include "Point.h"

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
    void drawByMidPoint() {
        glBegin(GL_POINTS);
        int x = a, y = 0;
        int a2 = a * a, b2 = b * b;
        int f = round(2.0 * a * b2 + b2 - a2 / 4);
        cout << f << endl;
        while (x <= 500) {
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
};