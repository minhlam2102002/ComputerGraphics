#include "RenderEngine.h"

RenderEngine *RenderEngine::renderEngine = nullptr;
RenderEngine *RenderEngine::getInstance() {
    if (renderEngine == nullptr)
        renderEngine = new RenderEngine();
    return renderEngine;
}
RenderEngine::RenderEngine() {
    this->state = 0;
    this->isClicked = false;
    this->color = RGBColor(1, 1, 1);
    this->canvas = new Canvas();
    this->isFilling = false;
}
// -----------------------------------------------------------
void RenderEngine::displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
    this->canvas->render();
    glFlush();
}
void RenderEngine::reshapeCallback(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, height, 0);
}
void RenderEngine::mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        this->mouseDown = Pixel(x, y);
        this->mouseMove = Pixel(x, y);
        this->isClicked = true;
        if (nameOf[this->state] == "Fill") {
            if (this->isFilling == false) {
                this->isFilling = true;
                RGBColor backgroundColor = this->canvas->getPixelColor(this->mouseDown);
                this->canvas->floodFill(this->mouseDown, backgroundColor, this->color);
                this->canvas->render();
                glFlush();
                this->isFilling = false;
            }
        }
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        this->mouseUp = Pixel(x, y);
        this->isClicked = false;
        this->canvas->capture();
    }
}
void RenderEngine::motionCallback(int x, int y) {
    if (!this->isClicked)
        return;
    if (nameOf[this->state] == "Brush") {
        drawFunctions["Line"](this->mouseMove, Pixel(x, y), this->color);
        this->mouseMove = Pixel(x, y);
    } else {
        glClear(GL_COLOR_BUFFER_BIT);
        this->canvas->render();
        this->mouseMove = Pixel(x, y);

        auto drawFunction = drawFunctions[nameOf[this->state]];
        drawFunction(this->mouseDown, this->mouseMove, this->color);
    }
    glFlush();
}
void RenderEngine::menuCallback(int option) {
    cout << "Selected: " << nameOf[option] << " option" << endl;

    for (int i = 0; i < colorNames.size(); i++) {
        if (nameOf[option] == colorNames[i]) {
            this->color = colorsMap[i];
            return;
        }
    }
    if (nameOf[option] == "Clear") {
        this->canvas->clear();
        this->canvas->render();
        glFlush();
        return;
    }
    if (nameOf[option] == "Exit") {
        exit(0);
    }
    this->state = option;
}