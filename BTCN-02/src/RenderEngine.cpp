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
    this->frame = new Frame();
    this->state = 0;
    cout << "Option 0 is chosen" << endl;
}
// -----------------------------------------------------------
void RenderEngine::onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        this->mouseDown = Pixel(x, y);
        this->mouseMove = Pixel(x, y);
        this->isClicked = true;
        if (this->state == Entry::idMap["Fill"]) {
            this->frame->fill(this->mouseDown, this->color);
            this->frame->display();
            glFlush();
        }
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
    if (this->state == Entry::idMap["Brush"]) {
        renderLine(this->mouseMove, Pixel(x, y));
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
void RenderEngine::renderObject(Pixel start, Pixel end) {
    if (this->state == Entry::idMap["Line"]) {
        renderLine(start, end);
    } else if (this->state == Entry::idMap["Rectangle"]) {
        renderRectangle(start, end);
    } else if (this->state == Entry::idMap["Square"]) {
        renderSquare(start, end);
    } else if (this->state == Entry::idMap["Circle"]) {
        renderCircle(start, end);
    } else if (this->state == Entry::idMap["Ellipse"]) {
        renderEllipse(start, end);
    } else if (this->state == Entry::idMap["Triangle"]) {
        renderTriangle(start, end);
    }
}