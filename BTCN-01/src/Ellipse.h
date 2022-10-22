#pragma once
#include "Point.h"

class Ellipse {
private:
    Point p;
    int a, b;
public:
    Ellipse(const vector<int> &args) {
        this->p = Point(args[0], args[1]);
        this->a = args[2];
        this->b = args[3];
    }
    float eval(const float &x, const float &y) const {
        const float a2 = a * a, b2 = b * b, x2 = x * x, y2 = y * y;
        return b2 * x2 + a2 * y2 - a2 * b2;
    }
    void drawByMidPoint() {
        int x = 0, y = b;
        const int a2 = a * a, b2 = b * b;
        int f = round(this->eval(x + 1, y - 0.5));
        int dx = 0, dy = 2 * a2 * y;

        glBegin(GL_POINTS);
        this->p.draw4SymPoints(x, y);
        while (dx < dy && isInWindow(x, y)) {
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
        f = round(this->eval(x + 0.5, y - 1));
        while (isInWindow(x, y)) {
            y--;
            if (f >= 0) {
                f += a2 * (3 - 2 * y);
            } else {
                x++;
                f += b2 * (2 * x + 2) + a2 * (3 - 2 * y);
            }
            this->p.draw4SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
    void drawByGL() {
        int d = M_PI * 2 * max(this->a, this->b);
        float angle = 0;
        const float angleInc = 2.0 * M_PI / d;
        int x, y;
        glBegin(GL_LINE_LOOP);
        while(d--) {
            angle += angleInc;
            x = round((float)this->p.x + this->a * cos(angle));
            y = round((float)this->p.y + this->b * sin(angle));
            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
};