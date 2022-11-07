#include "Window.h"

Window *Window::window = nullptr;
Window *Window::getInstance(int width, int height, int x, int y) {
    if (window == nullptr)
        window = new Window(width, height, x, y);
    return window;
}
Window *Window::getInstance() {
    if (window == nullptr)
        window = new Window(800, 600, 0, 0);
    return window;
}
Window::Window(int _width, int _height, int _x, int _y) {
    this->width = _width;
    this->height = _height;
    this->x = _x;
    this->y = _y;
}
void Window::init(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(this->width, this->height);
    glutInitWindowPosition(this->x, this->y);
}
void Window::setDisplayMode(int mode) {
    glutInitDisplayMode(mode);
}
void Window::setTitle(string title) {
    glutCreateWindow(title.c_str());
}
void Window::setBackgroundColor(float r, float g, float b) {
    glClearColor(r, g, b, 1.0);
}
void Window::setMouseCursor(int cursor) {
    glutSetCursor(cursor);
}
void Window::configureClippingArea() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, this->width, this->height, 0);
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
void Window::registerMouseCallback(void (*mouseCallback)(int button, int state, int x, int y)) {
    glutMouseFunc(mouseCallback);
}
void Window::reshapeCallback(GLsizei _width, GLsizei _height) {
    this->width = _width;
    this->height = _height;
    // glViewport(0, 0, this->width, this->height);
    // this->configureClippingArea();
}
void Window::start() {
    glutMainLoop();
}
void Window::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}
void Window::captureFrame(float *&frame) {
    if (frame == nullptr) {
        frame = new float[this->width * this->height * 3];
        cout << frame[0] << endl;
    }
    glReadPixels(0, 0, this->width, this->height, GL_RGB, GL_FLOAT, frame);
}
void Window::displayFrame(float *&frame) {
    glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, frame);
}