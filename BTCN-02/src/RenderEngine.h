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
    Point *mouseDown, *mouseUp, *mouseMove;
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
    void boundaryFill(Point *, RGBColor *);
    void fill();

public:
    void onMouseClick(int, int, int, int);
    void onMouseMove(int, int);
    void setState(int);
    void setColor(RGBColor *);
    void renderObject(Point *, Point *);
    void render();
};