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
        const int dx = this->p2.x - this->p1.x;
        const int dy = this->p2.y - this->p1.y;
        float x = this->p1.x;
        float y = this->p1.y;

        int step = max(abs(dx), abs(dy));
        const float xInc = (float)dx / step;
        const float yInc = (float)dy / step;
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
        const int dx = this->p2.x - this->p1.x;
        const int dy = this->p2.y - this->p1.y;
        int x = this->p1.x;
        int y = this->p1.y;
        int p = 2 * dy - dx;
        const int const1 = 2 * dy;
        const int const2 = 2 * (dy - dx);
        // running
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        if (dx > dy) {
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
        } else {
            while (y < this->p2.y) {
                if (p < 0) {
                    p += const1;
                    x++;
                } else {
                    p += const2;
                }
                y++;
                glVertex2i(x, y);
            }
        }
        glEnd();
        glFlush();
    }
};