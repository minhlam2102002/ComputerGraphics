#pragma once
#include "Canvas.h"
#include "DrawFunction.h"
#include "Menu.h"
#include "Object.h"

// -----------------------------------------------------------
class RenderEngine {
private:
    int state;
    RGBColor color;
    bool isClicked, isFilling;
    Pixel mouseDown, mouseUp, mouseMove;
    Canvas *canvas;
    vector<Object*> objects;

private:
    RenderEngine();
    static RenderEngine *renderEngine;

public:
    static RenderEngine *getInstance();
    RenderEngine(RenderEngine &) = delete;
    void operator=(const RenderEngine &) = delete;

public:
    void displayCallback();
    void reshapeCallback(int, int);
    void mouseCallback(int, int, int, int);
    void motionCallback(int, int);
    void menuCallback(int);
};