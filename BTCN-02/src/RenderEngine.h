#pragma once
#include "Window.h"
#include "library.h"
struct Point {
    int x, y;
    Point();
    Point(int x, int y);
    void vertex();
};
// -----------------------------------------------------------
struct RGBColor {
    float r, g, b;
    RGBColor();
    RGBColor(float r, float g, float b);
    RGBColor(float pixel[3]);
    void set();
};
// -----------------------------------------------------------
class RenderEngine {
private:
    int state;
    Point *mouseDown, *mouseUp;
    RGBColor *color;
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
    void setColor(RGBColor *);
    void renderObject(Point *, Point *);
    void render();
};