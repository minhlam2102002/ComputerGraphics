#pragma once
#include "Point.h"

class Ellipse {
private:
    Point p;
    int a, b;
    // f(x,y) = b^2x^2 + a^2y^2  – a^2b^2 
public:
    Ellipse(const vector<int> &args) {
        this->p = Point(args[0], args[1]);
        this->a = args[2];
        this->b = args[3];
    }
    void drawByMidPoint() {
        int x = 0, y = b;
        int a2 = a * a, b2 = b * b;
        int f = round(1.0 * b2 - a2*b + 0.25 * a2);
        int dx = 0, dy = 2 * a2 * y;
        glBegin(GL_POINTS);
        this->p.draw4SymPoints(x, y);
        while (dx < dy) {
            x++;
            dx += 2 * b2; 
            if (f < 0) {
                f += b2 * (2 * x + 3);
            } else {
                y--;
                dy -= 2 * a2;
                f += b2 * (2 * x + 3) + a2 * (2 - 2 * y);
            }
            this->p.draw4SymPoints(x, y);
        }
        f = round(1.0 * b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);
        while (y > 0) {
            y--;
            dy -= 2 * a2;
            if (f >= 0) {
                f += a2 * (3 - 2 * y);
            } else {
                x++;
                dx += 2 * b2;
                f += b2 * (2 * x + 2) + a2 * (3 - 2 * y);
            }
            this->p.draw4SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
    void drawByGL() {
        int num_segments = M_PI * 2 * max(this->a, this->b);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < num_segments; i++) {
            double angle = 2 * M_PI * i / num_segments;
            int x = round(1.0 * this->p.x + this->a * cos(angle));
            int y = round(1.0 * this->p.y + this->b * sin(angle));
            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
};