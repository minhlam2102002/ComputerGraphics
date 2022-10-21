#include "Point.h"

class Parabola {
private:
    Point p;
    int a;
public:
    Parabola(vector<int> args) {
        this->p = Point(args[0], args[1]);
        this->a = args[2];
    }
    float eval(const float &x, const float &y) const {
        return x * x - 4 * this->a * y;
    }
    void drawByMidPoint() {
        int x = 0, y = 0;
        int f = round(this->eval(x + 1, y + 0.5));
        int dx = 0, dy = -4 * this->a;

        glBegin(GL_POINTS);
        this->p.draw2SymPoints(x, y);
        while (dx < abs(dy) && isInWindow(x, y)) {
            x++;
            dx += 2;
            if (f < 0) {
                f += 2 * x + 3;
            } else {
                y++;
                f += 2 * x + 3 - 4 * this->a;
            }
            this->p.draw2SymPoints(x, y);
        }
        f = round(this->eval(x + 0.5, y + 1));
        while (isInWindow(x, y)) {
            y++;
            if (f >= 0) {
                f += -4 * this->a;
            } else {
                x++;
                f += -4 * this->a + 2 * x + 3;
            }
            this->p.draw2SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
    void drawByGL() {
        const int SIZE = 1000;
        int x = 0, y = 0;
        glBegin(GL_POINTS);
        this->p.draw2SymPoints(x, y);
        while (x <= 2 * this->a) {
            x++;
            y = x * x / (4 * this->a);
            this->p.draw2SymPoints(x, y);
        }
        while (this->p.x + x < SIZE && this->p.y + y < SIZE && this->p.x - x > 500 && this->p.x - x > 500) {
            y++;
            x = sqrt(4 * this->a * y);
            this->p.draw2SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
};