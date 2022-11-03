#pragma once
#include "../library.h"
#include "../geometry/Color.h"
class Window {
private:
    static Window *_window;
    int _width, _height;
    int _x, _y;
    Window(int width, int height, int x, int y);
public:
    static Window *getInstance();
    static Window *getInstance(int width, int height, int x, int y);
    Window(Window &) = delete;
    void operator=(const Window &) = delete;
public:
    void init(int argc, char **argv);
    void setTitle(string);
    void setBackgroundColor(float r, float g, float b);
    void setMouseCursor(int);
    void configureClippingArea();
    void registerDisplayCallback(void (*)(void));
    void registerReshapeCallback(void (*)(GLsizei, GLsizei));
    void registerMouseCallback(void (*func)(int button, int state,int x, int y));
    void registerMotionCallback(void (*func)(int x, int y));
    void registerPassiveMotionCallback(void (*func)(int x, int y));
    void clearScreen();
    void start();
    RGBColor* getPixelColor(int x, int y);
};
