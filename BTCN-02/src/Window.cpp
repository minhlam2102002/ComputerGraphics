#include "Window.h"

Pixel::Pixel() : Pixel(0, 0) {}
Pixel::Pixel(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}
void Pixel::set() {
    glVertex2i(this->x, this->y);
}
// -----------------------------------------------------------
RGBColor::RGBColor() : RGBColor(0, 0, 0) {}
RGBColor::RGBColor(float _r, float _g, float _b) {
    this->r = _r;
    this->g = _g;
    this->b = _b;
}
void RGBColor::set() {
    glColor3f(this->r, this->g, this->b);
}
// -----------------------------------------------------------
Frame::Frame() : Frame(Window::width, Window::height) {}
Frame::Frame(int _width, int _height) {
    this->width = _width;
    this->height = _height;
    this->frame = new float[_width * _height * RGBColor::BYTE_SIZE];
}
void Frame::capture() {
    glReadPixels(0, 0, this->width, this->height, GL_RGB, GL_FLOAT, this->frame);
}
void Frame::display() {
    glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, this->frame);
}
RGBColor* Frame::getPixelColor(Pixel* p) {
    int i = (p->y * this->width + p->x) * RGBColor::BYTE_SIZE;
    return new RGBColor(this->frame[i], this->frame[i + 1], this->frame[i + 2]);
}
void Frame::setPixelColor(Pixel* p, RGBColor* color) {
    int i = (p->y * this->width + p->x) * RGBColor::BYTE_SIZE;
    this->frame[i] = color->r;
    this->frame[i + 1] = color->g;
    this->frame[i + 2] = color->b;
}
// -----------------------------------------------------------
Window* Window::window = nullptr;
int Window::width = 800;
int Window::height = 600;
Window* Window::getInstance(int width, int height) {
    if (window == nullptr)
        window = new Window(width, height);
    return window;
}
Window* Window::getInstance() {
    if (window == nullptr)
        window = new Window(Window::width, Window::height);
    return window;
}
// -----------------------------------------------------------
Window::Window(int _width, int _height) {
    Window::width = _width;
    Window::height = _height;
}
void Window::init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(Window::width, Window::height);
    glutInitWindowPosition(0, 0);
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
void Window::registerMotionCallback(void (*motionCallback)(int, int)) {
    glutMotionFunc(motionCallback);
}
void Window::registerPassiveMotionCallback(void (*passiveMotionCallback)(int, int)) {
    glutPassiveMotionFunc(passiveMotionCallback);
}
void Window::registerMouseCallback(void (*mouseCallback)(int, int, int, int)) {
    glutMouseFunc(mouseCallback);
}
void Window::reshapeCallback(GLsizei _width, GLsizei _height) {
    Window::width = _width;
    Window::height = _height;
    // glViewport(0, 0, this->width, this->height);
    // this->configureClippingArea();
}
void Window::start() {
    glutMainLoop();
}
void Window::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}
