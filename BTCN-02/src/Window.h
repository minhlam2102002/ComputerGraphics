#pragma once
#include "library.h"

struct Pixel {
    int x, y;
    Pixel();
    Pixel(int, int);
    void set();
};
// -----------------------------------------------------------
struct RGBColor {
    static const int BYTE_SIZE = 3;
    float r, g, b;
    RGBColor();
    RGBColor(float, float, float);
    void set();
};
// -----------------------------------------------------------
class Frame {
private:
    int width, height;
    float *frame;

public:
    Frame();
    Frame(int, int);
    void display();
    void capture();
    RGBColor *getPixelColor(Pixel *);
    void setPixelColor(Pixel *, RGBColor *);
};
// -----------------------------------------------------------
class Window {
public:
    static int width, height;

private:
    static Window *window;
    Window(int, int);

public:
    static Window *getInstance();
    static Window *getInstance(int, int);
    Window(Window &) = delete;
    void operator=(const Window &) = delete;

public:
    void init(int, char **);
    void setDisplayMode(int);
    void setTitle(string);
    void setBackgroundColor(float, float, float);
    void setMouseCursor(int);
    void configureClippingArea();
    void registerDisplayCallback(void (*)(void));
    void registerReshapeCallback(void (*)(GLsizei, GLsizei));
    void registerMouseCallback(void (*)(int, int, int, int));
    void registerMotionCallback(void (*)(int, int));
    void registerPassiveMotionCallback(void (*)(int, int));
    void reshapeCallback(GLsizei, GLsizei);
    void clearScreen();
    Frame *getNewFrame();
    void start();
};