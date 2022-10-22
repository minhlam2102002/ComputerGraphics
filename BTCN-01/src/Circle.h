#pragma once
#include "Point.h"

class Circle {
private:
    Point p;
    int r;
public:
    Circle(const vector<int> &args) {
        this->p = Point(args[0], args[1]);
        this->r = args[2];
    }
    void drawByMidPoint() {
        int x = 0, y = this->r;
        int f = 1 - this->r;
        
        glBegin(GL_POINTS);
        this->p.draw8SymPoints(x, y);
        while (x < y && isInWindow(x, y)) {
            x++;
            if (f < 0) {
                f += 2 * x + 3;
            } else {
                f += 2 * (x - y) + 5;
                y--;
            }
            this->p.draw8SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
    void drawByGL() {
        int d = M_PI * 2 * this->r;
        float angle = 0;
        const float angleInc = 2 * M_PI / d;
        int x, y;
        glBegin(GL_LINE_LOOP);
        while (d--) {
            angle += angleInc;
            x = round((float)this->p.x + this->r * cos(angle));
            y = round((float)this->p.y + this->r * sin(angle));
            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
};