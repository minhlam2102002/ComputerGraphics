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
    void drawByMidPoint() {
        const int SIZE = 500;
        int x = 0, y = 0;
        int f = 1 - 2 * this->a;
        glBegin(GL_POINTS);
        this->p.draw2SymPoints(x, y);
        // while (this->p.x + x < SIZE && this->p.y + y < SIZE && this->p.x - x > 0 && this->p.x - x > 0) {
        while (x <= 2 * this->a) {
            x++;
            if (f < 0) {
                f += 2 * x + 1;
            } else {
                y++;
                f += 2 * x + 1 - 4 * this->a;
            }
            this->p.draw2SymPoints(x, y);
        }
        f = round(4*x*x + 4*x + 1 - 16 * this->a * (y - 1));
        while (this->p.x + x < SIZE && this->p.y + y < SIZE && this->p.x - x > 0 && this->p.x - x > 0) {
            y++;
            if (f < 0) {
                f += -16 * this->a;
            } else {
                x++;
                f += -16 * this->a + 8 * x;
            }
            cout << x << ' ' << y << endl;
            this->p.draw2SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
    void drawByGL() {
        const int SIZE = 1000;
        glBegin(GL_POINTS);
        int x = 0, y = 0;
        this->p.draw2SymPoints(x, y);
        while (x <= 2 * this->a) {
            x++;
            y = x * x / (4 * this->a);
            this->p.draw2SymPoints(x, y);
        }
        while (this->p.x + x < SIZE && this->p.y + y < SIZE && this->p.x - x > 500 && this->p.x - x > 500) {
            y++;
            x = sqrt(4 * this->a * y);
            cout << x << ' ' << y << endl;
            this->p.draw2SymPoints(x, y);
        }
        glEnd();
        glFlush();
    }
};