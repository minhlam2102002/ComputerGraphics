#pragma once
#include "library.h"

class Window {
private:
    static Window *window;
    int width, height;
    int x, y;
    Window(int, int, int, int);

public:
    static Window *getInstance();
    static Window *getInstance(int, int, int, int);
    Window(Window &) = delete;
    void operator=(const Window &) = delete;

public:
    void init(int, char **);
    void setDisplayMode(int);
    void setTitle(string);
    void setBackgroundColor(float r, float g, float b);
    void setMouseCursor(int);
    void configureClippingArea();
    void registerDisplayCallback(void (*)(void));
    void registerReshapeCallback(void (*)(GLsizei, GLsizei));
    void registerMouseCallback(void (*)(int, int, int, int));
    void registerMotionCallback(void (*)(int, int));
    void registerPassiveMotionCallback(void (*)(int, int));
    void reshapeCallback(GLsizei, GLsizei);
    void clearScreen();
    void captureFrame(float*&);
    void displayFrame(float*&);
    void start();
};