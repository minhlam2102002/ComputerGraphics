#include "Object.h"
void renderLine(Pixel start, Pixel end) {
    glBegin(GL_LINES);
    glVertex2i(start.x, start.y);
    glVertex2i(end.x, end.y);
    glEnd();
}
void renderRectangle(Pixel start, Pixel end) {
    glBegin(GL_LINE_LOOP);
    glVertex2i(start.x, start.y);
    glVertex2i(end.x, start.y);
    glVertex2i(end.x, end.y);
    glVertex2i(start.x, end.y);
    glEnd();
}
void renderSquare(Pixel start, Pixel end) {
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int signX = dx > 0 ? 1 : -1;
    int signY = dy > 0 ? 1 : -1;
    int sideLength = min(abs(dx), abs(dy));
    end = Pixel(start.x + sideLength * signX, start.y + sideLength * signY);
    glBegin(GL_LINE_LOOP);
    glVertex2i(start.x, start.y);
    glVertex2i(end.x, start.y);
    glVertex2i(end.x, end.y);
    glVertex2i(start.x, end.y);
    glEnd();
}
void renderCircle(Pixel start, Pixel end) {
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int signX = dx > 0 ? 1 : -1;
    int signY = dy > 0 ? 1 : -1;
    int radius = max(abs(dx), abs(dy)) / 2;
    Pixel center = Pixel(start.x + signX * radius, start.y + signY * radius);
    int perimeter = 2.0 * M_PI * radius;
    float angle = 0;
    const float angleInc = 2.0 * M_PI / perimeter;
    int x, y;
    glBegin(GL_LINE_LOOP);
    while (perimeter--) {
        angle += angleInc;
        x = round((float)center.x + radius * cos(angle));
        y = round((float)center.y + radius * sin(angle));
        glVertex2i(x, y);
    }
    glEnd();
}
void renderEllipse(Pixel start, Pixel end) {
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int a = abs(dx) / 2;
    int b = abs(dy) / 2;
    Pixel center = Pixel((start.x + end.x) / 2, (start.y + end.y) / 2);
    int perimeter = M_PI * 2 * max(a, b);
    float angle = 0;
    const float angleInc = 2.0 * M_PI / perimeter;
    int x, y;
    glBegin(GL_LINE_LOOP);
    while (perimeter--) {
        angle += angleInc;
        x = round((float)center.x + a * cos(angle));
        y = round((float)center.y + b * sin(angle));
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}
void renderTriangle(Pixel start, Pixel end) {
}
