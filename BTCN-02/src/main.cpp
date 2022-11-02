#include "views/Window.h"
#include "views/Menu.h"
// #include "Line.h"
// #include "Point.h"
// #include "Circle.h"
// #include "Ellipse.h"
// #include "Parabola.h"
// #include "Hyperbola.h"

void displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void reshapeCallback(GLsizei width, GLsizei height) {
    glClear(GL_COLOR_BUFFER_BIT);
}

void menuCallback(int option) {
    cout << "Option " << option << " is selected" << endl;
    glutPostRedisplay();
}
void createMenu() {
    Menu* menu = new Menu("Main");
    cout << "Menu initialized" << endl;
    menu->registerMenuCallback(menuCallback);
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
    menu->create();
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void mouseCallback(int button, int state,int x, int y) {
    cout << "Mouse clicked at (" << x << ", " << y << ")" << " with button " << button << " and state " << state << endl;
}


int main(int argc, char** argv) {
    Window* window = Window::getInstance(1000, 600, 100, 100);
    window->init(argc, argv);
    window->setTitle("Computer Graphics");
    window->setBackgroundColor(0.9, 0.9, 0.9);
    window->configureClippingArea();
    window->setMouseCursor(GLUT_CURSOR_CROSSHAIR);
    window->registerDisplayCallback(displayCallback);
    window->registerReshapeCallback(reshapeCallback);
    window->registerMouseCallback(mouseCallback);
    createMenu();
    window->start();
    return 0;
}
