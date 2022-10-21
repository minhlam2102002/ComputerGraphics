#pragma once
#include "Point.h"
class Line {
private:
    Point p1, p2;
public:
    Line(vector<int> args) {
        this->p1 = Point(args[0], args[1]);
        this->p2 = Point(args[2], args[3]);
    }
    void drawByGL() {
        glBegin(GL_LINES);
            glVertex2i(this->p1.x, this->p1.y);
            glVertex2i(this->p2.x, this->p2.y);
        glEnd();
        glFlush();
    }
    void drawByDDA() {
        // DDA is short for Digital Differential Analyzer
        int dx = this->p2.x - this->p1.x;
        int dy = this->p2.y - this->p1.y;
        float x = this->p1.x;
        float y = this->p1.y;

        int step = max(abs(dx), abs(dy));
        float xInc = 1.0 * dx / step;
        float yInc = 1.0 * dy / step;
        // running
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        while (step--) {
            x += xInc;
            y += yInc;
            glVertex2i(round(x), round(y));
        }
        glEnd();
        glFlush();
    }
    void drawByBresenham() {
        float dx = this->p2.x - p1.x;
        float dy = this->p2.y - p1.y;
        float x = p1.x, y = p1.y;
        float p = 2 * dy - dx;
        float const1 = 2 * dy;
        float const2 = 2 * (dy - dx);
        // running
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        while (x < this->p2.x) {
            if (p < 0) {
                p += const1;
            } else {
                p += const2;
                y++;
            }
            x++;
            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
};