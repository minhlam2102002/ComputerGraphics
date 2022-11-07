#pragma once
#include "Geometry.h"

class RenderEngine {
private:
    int state;
    Point mouseDown, mouseUp;
    RGBColor color;
    float *frame;

private:
    RenderEngine();
    static RenderEngine *renderEngine;

public:
    static RenderEngine *getInstance();
    RenderEngine(RenderEngine &) = delete;
    void operator=(const RenderEngine &) = delete;
private:
    void fill();
public:
    void onMouseClick(int button, int state, int x, int y);
    void onMouseMove(int x, int y);
    void setState(int option);
    void setColor(RGBColor);
    void capture();
    void renderObject(Point, Point);
    void render();
};