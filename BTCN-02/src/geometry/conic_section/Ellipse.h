#pragma once
#include "../basic/Point.h"

class Ellipse : public GeometryObject {
private:
    Point p;
    int a, b;
public:
    Ellipse(Point p, int a, int b) {
        this->p = p;
        this->a = a;
        this->b = b;
    }
    float eval(const float &x, const float &y) const {
        const float a2 = a * a, b2 = b * b, x2 = x * x, y2 = y * y;
        return b2 * x2 + a2 * y2 - a2 * b2;
    }
    void render() {
        int x = 0, y = b;
        const int a2 = a * a, b2 = b * b;
        int f = round(this->eval(x + 1, y - 0.5));
        int dx = 0, dy = 2 * a2 * y;

        glBegin(GL_POINTS);
        this->p.render4SymPoints(x, y);
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
            this->p.render4SymPoints(x, y);
        }
        f = round(this->eval(x + 0.5, y - 1));
        while (y > 0) {
            y--;
            if (f >= 0) {
                f += a2 * (3 - 2 * y);
            } else {
                x++;
                f += b2 * (2 * x + 2) + a2 * (3 - 2 * y);
            }
            this->p.render4SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
};