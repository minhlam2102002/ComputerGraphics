#include "Window.h"

Window *Window::_window = nullptr;
Window *Window::getInstance(int width, int height, int x, int y) {
    if (_window == nullptr) {
        _window = new Window(width, height, x, y);
    }
    return _window;
}
Window *Window::getInstance() { 
    return _window; 
}
Window::Window(int width, int height, int x, int y) {
    this->_width = width;
    this->_height = height;
    this->_x = x;
    this->_y = y;
}

void Window::init(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(this->_width, this->_height);
    glutInitWindowPosition(this->_x, this->_y);
}
void Window::setTitle(string title) {
    glutCreateWindow(title.c_str());
}

void Window::setBackgroundColor(float r, float g, float b) {
    glClearColor(r, g, b, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
void Window::setMouseCursor(int cursor) {
    glutSetCursor(cursor);
}
void Window::configureClippingArea() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, this->_width, this->_height, 0);
}
void Window::registerDisplayCallback(void (*displayCallback)(void)) {
    glutDisplayFunc(displayCallback);
}
void Window::registerReshapeCallback(void (*reshapeCallback)(GLsizei, GLsizei)) {
    glutReshapeFunc(reshapeCallback);
}
void Window::registerMotionCallback(void (*motionCallback)(int x, int y)) {
    glutMotionFunc(motionCallback);
}
void Window::registerPassiveMotionCallback(void (*passiveMotionCallback)(int x, int y)) {
    glutPassiveMotionFunc(passiveMotionCallback);
}
void Window::start() { 
    glutMainLoop(); 
}
void Window::registerMouseCallback(void (*mouseCallback)(int button, int state,int x, int y)) {
    glutMouseFunc(mouseCallback);
}
RGBColor* Window::getPixelColor(int x, int y) {
    float pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &pixel);
    RGBColor* color = new RGBColor(pixel);
    return color;
}
void Window::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}