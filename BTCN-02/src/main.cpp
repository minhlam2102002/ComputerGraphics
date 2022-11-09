#include "Menu.h"
#include "RenderEngine.h"
#include "Window.h"

void displayCallback() {
    RenderEngine::getInstance()->render();
    glFlush();
}
void reshapeCallback(GLsizei width, GLsizei height) {
    glClear(GL_COLOR_BUFFER_BIT);
    Window::getInstance()->reshapeCallback(width, height);
    glFlush();
}
void menuCallback(int option) {
    cout << "Option " << option << " is chosen." << endl;
    RenderEngine::getInstance()->setState(option);
}
void mouseCallback(int button, int state, int x, int y) {
    RenderEngine::getInstance()->onMouseClick(button, state, x, y);
}
void motionCallback(int x, int y) {
    RenderEngine::getInstance()->onMouseMove(x, y);
}
void createMenu() {
    Menu* menu = new Menu("Main");
    menu->addEntries({"Brush"});
    menu->addEntries({"Line"});
    menu->addSubMenu("Quadrangle")
        ->addEntries({"Rectangle", "Square"});
    menu->addSubMenu("ConicSection")
        ->addEntries({"Circle", "Ellipse"});
    menu->addSubMenu("Polygon")
        ->addEntries({"Pentagon", "Hexagon"});
    menu->addSubMenu("Shape")
        ->addEntries({"Arrow", "Star"});
    menu->addSubMenu("Operator")
        ->addEntries({"Plus", "Minus", "Multiply", "Divide"});
    menu->addSubMenu("FillColor")
        ->addEntries({"Blue", "Red", "Yellow"});
    menu->addEntries({"Erase"});
    menu->addEntries({"Clear"});
    menu->addEntries({"Quit"});
    menu->create(menuCallback);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
    Window* window = Window::getInstance(1000, 600);
    window->init(argc, argv);
    window->setDisplayMode(GLUT_SINGLE | GLUT_RGB);
    window->setTitle("My Paint");
    // window->setBackgroundColor(0.9, 0.9, 0.9);
    window->setMouseCursor(GLUT_CURSOR_CROSSHAIR);
    window->configureClippingArea();
    window->registerDisplayCallback(displayCallback);
    window->registerReshapeCallback(reshapeCallback);
    window->registerMouseCallback(mouseCallback);
    window->registerMotionCallback(motionCallback);
    createMenu();
    window->start();
    return 0;
}
