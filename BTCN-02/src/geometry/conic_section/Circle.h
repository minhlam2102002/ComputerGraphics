#include "../basic/Point.h"

class Circle : public GeometryObject {
private:
    Point p;
    int r;
public:
    Circle(Point p, int r) {
        this->p = p;
        this->r = r;
    }
    void render() {
        int x = 0, y = this->r;
        int f = 1 - this->r;
        
        glBegin(GL_POINTS);
        this->p.draw8SymPoints(x, y);
        while (x < y) {
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
};