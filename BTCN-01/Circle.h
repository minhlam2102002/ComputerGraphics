#pragma once
#include "Point.h"

class Circle {
private:
    Point p;
    int r;

public:
    Circle(Point p, int r) {
        this->p = p;
        this->r = r;
    }
    Circle(const vector<int> &args) {
        this->p = Point(args[0], args[1]);
        this->r = args[2];
    }
    void draw8symPoints(int x, int y) {
        int dx[] = {1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1};
        for (int i = 0; i < 4; i++) {
            glVertex2i(this->p.x + x * dx[i], this->p.y + y * dy[i]);
            glVertex2i(this->p.x + y * dx[i], this->p.y + x * dy[i]);
        }
    }
    void drawByMidPoint() {
        int x = 0, y = this->r;
        int f = 1 - this->r;
        
        glBegin(GL_POINTS);
        draw8symPoints(x, y);
        while (x < y) {
            if (f < 0) {
                f += 2 * x + 3;
            } else {
                f += 2 * (x - y) + 5;
                y--;
            }
            x++;
            draw8symPoints(x, y);
        }
        glEnd();
        glFlush();
    }
    void drawByGL() {
        int num_segments = M_PI * 2 * this->r;
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < num_segments; i++) {
            double angle = 2 * M_PI * i / num_segments;
            int x = round(1.0 * this->p.x + this->r * cos(angle));
            int y = round(1.0 * this->p.y + this->r * sin(angle));
            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
};