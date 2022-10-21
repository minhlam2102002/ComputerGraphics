#pragma once
#include "Point.h"
class Line {
private:
    Point p1, p2;
public:
    Line() {
        this->p1 = Point();
        this->p2 = Point();
    }
    Line(Point A, Point B) {
        this->p1 = A;
        this->p2 = B;
    }
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
        int dx = this->p2.x - p1.x;
        int dy = this->p2.y - p1.y;
        double m = 1.0 * dy / dx;
        int x = p1.x;
        double y = p1.y;
        // running
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        while (x < this->p2.x) {
            x += 1;
            y += m;
            glVertex2i(x, round(y));
        }
        glEnd();
        glFlush();
    }
    void drawByBresenham() {
        double dx = this->p2.x - p1.x;
        double dy = this->p2.y - p1.y;
        double x = p1.x, y = p1.y;
        double p = 2 * dy - dx;
        double const1 = 2 * dy;
        double const2 = 2 * (dy - dx);
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