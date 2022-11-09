#include "Menu.h"
#include "RenderEngine.h"
#include "Window.h"
#include "Object.h"

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
    if (option == Entry::idMap["Exit"]) {
        exit(0);
    }
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
    menu->addSubMenu("Color")
        ->addEntries({"Red", "Green", "Blue", "Yellow", "Purple", "Cyan", "White"});
    menu->addEntries({"Fill"});
    menu->addEntries({"Erase"});
    menu->addEntries({"Clear"});
    menu->addEntries({"Exit"});
    menu->create(menuCallback);
    menu->attachTo(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
    Window* window = Window::getInstance();
    window->init(argc, argv);
    window->setSize(1000, 800);
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
