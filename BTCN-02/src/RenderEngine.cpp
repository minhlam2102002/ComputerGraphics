#include "RenderEngine.h"

Point::Point() { x = y = 0; }
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
void Point::vertex() {
    glVertex2i(x, y);
}
// -----------------------------------------------------------
RGBColor::RGBColor() {
    this->r = this->b = this->g = 0;
}
RGBColor::RGBColor(GLfloat r, GLfloat g, GLfloat b) {
    this->r = r;
    this->g = g;
    this->b = b;
}
RGBColor::RGBColor(GLfloat pixel[3]) {
    this->r = pixel[0];
    this->g = pixel[1];
    this->b = pixel[2];
}
void RGBColor::set() {
    glColor3f(r, g, b);
}
// -----------------------------------------------------------
RenderEngine *RenderEngine::renderEngine = nullptr;
RenderEngine *RenderEngine::getInstance() {
    if (renderEngine == nullptr)
        renderEngine = new RenderEngine();
    return renderEngine;
}
RenderEngine::RenderEngine() {
    this->mouseDown = this->mouseUp = nullptr;
    this->color = new RGBColor(1, 0, 0);
    this->color->set();
    this->state = 0;
    this->frame = nullptr;
}
// -----------------------------------------------------------
void RenderEngine::onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        this->mouseDown = new Point(x, y);
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        this->mouseUp = new Point(x, y);
        Window::getInstance()->captureFrame(this->frame);
    }
}
void RenderEngine::onMouseMove(int x, int y) {
    if (this->state != 0) {
        glClear(GL_COLOR_BUFFER_BIT);
        this->render();
    }
    if (this->mouseDown != nullptr) {
        Point *mouseMove = new Point(x, y);
        this->renderObject(this->mouseDown, mouseMove);
    }
    glFlush();
}
void RenderEngine::setState(int option) {
    this->state = option;
}
void RenderEngine::setColor(RGBColor* _color) {
    this->color = _color;
    this->color->set();
}
void RenderEngine::render() {
    Window::getInstance()->displayFrame(this->frame);
}
void RenderEngine::fill() {
    Point *p = this->mouseDown;
}

void RenderEngine::renderObject(Point *start, Point *end) {
    if (this->state == 0) {
        glBegin(GL_POINTS);
        glVertex2i(end->x, end->y);
        glEnd();
    } else if (this->state == 1) {
        glBegin(GL_LINES);
        glVertex2i(start->x, start->y);
        glVertex2i(end->x, end->y);
        glEnd();
    } else if (this->state == 2) {
        glBegin(GL_LINE_LOOP);
        glVertex2i(start->x, start->y);
        glVertex2i(end->x, start->y);
        glVertex2i(end->x, end->y);
        glVertex2i(start->x, end->y);
        glEnd();
    }
}