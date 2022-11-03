#pragma once
#include "Point.h"
#include "../../views/Window.h"
class Line : public GeometryObject {
private:
    vector<Point*> points;
public:
    void remove() {
        Window::getInstance()->clearScreen();
    }
    void render(Point *p1, Point *p2, RGBColor *color, int layer) {
        cout << "Rendering line " << p1->x << " " << p1->y << " " << p2->x << " " << p2->y << endl;
        Window *window = Window::getInstance();
        window->clearScreen();
        const int dx = p2->x - p1->x;
        const int dy = p2->y - p1->y;
        float x = p1->x;
        float y = p1->y;
        int step = max(abs(dx), abs(dy));
        const float xInc = (float)dx / step;
        const float yInc = (float)dy / step;
        // running
        points.clear();
        // RGBAColor* c = window->getPixelColor(round(x), round(y));
        this->points.push_back(new Point(x, y));
        while (step--) {
            x += xInc;
            y += yInc;
            // c = window->getPixelColor(round(x), round(y));
            this->points.push_back(new Point(round(x), round(y)));
        }
        color->set();
        glBegin(GL_POINTS);
        for (Point *p : this->points) {
            p->setVertex(layer);
        }
        glEnd();
        glFlush();
    }
};