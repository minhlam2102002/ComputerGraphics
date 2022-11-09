#pragma once
#include "library.h"

struct Pixel {
    int x, y;
    Pixel();
    Pixel(int, int);
    void set();
    Pixel operator+(const Pixel &);
    Pixel operator+=(const Pixel &);
    Pixel operator-(const Pixel &);
};
// -----------------------------------------------------------
struct RGBColor {
    static const int BYTE_SIZE = 3;
    float r, g, b;
    RGBColor();
    RGBColor(float, float, float);
    void set();
    bool operator==(const RGBColor&);
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
    RGBColor getPixelColor(Pixel);
    void setPixelColor(Pixel, RGBColor);
    bool possess(Pixel);
};
// -----------------------------------------------------------
class Window {
private:
    int width, height;
    static Window *window;
    Window();

public:
    static Window *getInstance();
    static int getWidth();
    static int getHeight();
    Window(Window &) = delete;
    void operator=(const Window &) = delete;

public:
    void init(int, char **);
    void setSize(int, int);
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
    void start();
};