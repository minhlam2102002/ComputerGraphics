#include "RenderEngine.h"

RenderEngine *RenderEngine::renderEngine = nullptr;
RenderEngine *RenderEngine::getInstance() {
    if (renderEngine == nullptr)
        renderEngine = new RenderEngine();
    return renderEngine;
}
RenderEngine::RenderEngine() {
    this->color = RGBColor(1, 1, 1);
    this->color.set();
    this->isClicked = false;
    this->state = 0;
    this->frame = new Frame();
}
// -----------------------------------------------------------
void RenderEngine::onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        this->mouseDown = Pixel(x, y);
        this->mouseMove = Pixel(x, y);
        this->isClicked = true;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        this->mouseUp = Pixel(x, y);
        this->isClicked = false;
        this->frame->capture();
    }
}
void RenderEngine::onMouseMove(int x, int y) {
    if (!this->isClicked)
        return;
    if (this->state == 0) {
        glBegin(GL_LINES);
        glVertex2i(this->mouseMove.x, this->mouseMove.y);
        glVertex2i(x, y);
        glEnd();
        this->mouseMove = Pixel(x, y);
    } else {
        glClear(GL_COLOR_BUFFER_BIT);
        this->render();
        this->mouseMove = Pixel(x, y);
        this->renderObject(this->mouseDown, this->mouseMove);
    }
    glFlush();
}
void RenderEngine::setState(int option) {
    this->state = option;
}
void RenderEngine::setColor(RGBColor _color) {
    this->color = _color;
    this->color.set();
}
void RenderEngine::render() {
    this->frame->display();
}
// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, 1, 0, -1};
void RenderEngine::boundaryFill(Pixel cur, RGBColor color) {
}
void RenderEngine::fill() {
    this->boundaryFill(this->mouseDown, this->color);
}
void RenderEngine::renderObject(Pixel start, Pixel end) {
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int signX = dx > 0 ? 1 : -1;
    int signY = dy > 0 ? 1 : -1;
    if (this->state == 1) {
        glBegin(GL_LINES);
        glVertex2i(start.x, start.y);
        glVertex2i(end.x, end.y);
        glEnd();
    } else if (this->state == 2) {
        glBegin(GL_LINE_LOOP);
        glVertex2i(start.x, start.y);
        glVertex2i(end.x, start.y);
        glVertex2i(end.x, end.y);
        glVertex2i(start.x, end.y);
        glEnd();
    }
    if (this->state == 3) {
        int sideLength = min(abs(dx), abs(dy));
        Pixel squareEnd = Pixel(start.x + sideLength * signX, start.y + sideLength * signY);
        glBegin(GL_LINE_LOOP);
        glVertex2i(start.x, start.y);
        glVertex2i(squareEnd.x, start.y);
        glVertex2i(squareEnd.x, squareEnd.y);
        glVertex2i(start.x, squareEnd.y);
        glEnd();
    } else if (this->state == 4) {
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
    } else if (this->state == 5) {
        int a = abs(dx) / 2;
        int b = abs(dy) / 2;
        Pixel center = Pixel((start.x + end.x)/2, (start.y + end.y)/2);
        int perimeter = M_PI * 2 * max(a, b);
        float angle = 0;
        const float angleInc = 2.0 * M_PI / perimeter;
        int x, y;
        glBegin(GL_LINE_LOOP);
        while(perimeter--) {
            angle += angleInc;
            x = round((float)center.x + a * cos(angle));
            y = round((float)center.y + b * sin(angle));
            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
}