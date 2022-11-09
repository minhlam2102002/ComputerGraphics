#pragma once
#include "Window.h"
#include "Menu.h"
#include "Object.h"

// -----------------------------------------------------------
class RenderEngine {
private:
    int state;
    Pixel mouseDown, mouseUp, mouseMove;
    bool isClicked;
    RGBColor color;
    Frame *frame;

private:
    RenderEngine();
    static RenderEngine *renderEngine;

public:
    static RenderEngine *getInstance();
    RenderEngine(RenderEngine &) = delete;
    void operator=(const RenderEngine &) = delete;

private:
    void boundaryFill(Pixel, RGBColor, RGBColor);
    void fill();

public:
    void onMouseClick(int, int, int, int);
    void onMouseMove(int, int);
    void setState(int);
    void setColor(RGBColor);
    void renderObject(Pixel, Pixel);
    void render();
};