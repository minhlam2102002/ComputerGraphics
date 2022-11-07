#include "RenderEngine.h"

#include "Menu.h"

RenderEngine *RenderEngine::renderEngine = nullptr;
RenderEngine::RenderEngine() {
    this->color = RGBColor(1, 0, 0);
    this->color.set();
    this->state = 0;
    this->frame = new float[SCREEN_WIDTH * SCREEN_HEIGHT * 3];
}
RenderEngine *RenderEngine::getInstance() {
    if (renderEngine == nullptr)
        renderEngine = new RenderEngine();
    return renderEngine;
}

void RenderEngine::onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        cout << "Mouse Down: " << x << ", " << y << endl;
        this->mouseDown = Point(x, y);
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        this->mouseUp = Point(x, y);
        this->capture();
    }
}
void RenderEngine::onMouseMove(int x, int y) {
    glClear(GL_COLOR_BUFFER_BIT);
    this->render();
    this->renderObject(this->mouseDown, Point(x, y));
    glFlush();
}
void RenderEngine::setState(int option) {
    this->state = option;
}
void RenderEngine::setColor(RGBColor _color) {
    this->color = _color;
    this->color.set();
}
void RenderEngine::capture() {
    glReadPixels(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_FLOAT, this->frame);
}
void RenderEngine::render() {
    glDrawPixels(SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_FLOAT, this->frame);
}
void RenderEngine::fill() {
    Point p = this->mouseDown;
}

void RenderEngine::renderObject(Point start, Point end) {
    if (this->state == 0) {
        glBegin(GL_POINTS);
        glVertex2i(end.x, end.y);
        glEnd();
    } else if (this->state == 1) {
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
}