#pragma once
#include "../library.h"
#include "basic/Line.h"
#include "basic/Point.h"

class RenderEngine {
private:
    int _state;
    int layer;
    RGBColor* color;
    Point *mouseDown, *mouseUp;
    GeometryObject *object;
    vector<GeometryObject *> renderHistory;
private:
    RenderEngine();
    static RenderEngine *renderEngine;
public:
    static RenderEngine *getInstance();
    RenderEngine(RenderEngine &) = delete;
    void operator=(const RenderEngine &) = delete;
public:
    void onMouseClick(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            this->mouseDown = new Point(x, y);
            object = new Line;
            // this->renderHistory.push_back(object);
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            this->mouseUp = new Point(x, y);
            object = nullptr;
        }
    }
    void onMouseMove(int x, int y) {
        this->color = new RGBColor(1, 0, 0);
        object->render(this->mouseDown, new Point(x, y), this->color, this->layer);
    }
    void onMousePassiveMove(int x, int y) {}
    void setRenderState(int state) {
        this->_state = state;
    }
};