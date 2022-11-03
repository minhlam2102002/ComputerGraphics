#include "views/Menu.h"
#include "views/Window.h"
#include "geometry/RenderEngine.h"
void displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
}
void reshapeCallback(GLsizei width, GLsizei height) {
    glClear(GL_COLOR_BUFFER_BIT);
}
void menuCallback(int option) {
    cout << "Option " << option << " selected" << endl;
    RenderEngine::getInstance()->setRenderState(option);
}
void mouseCallback(int button, int state, int x, int y) {
    RenderEngine::getInstance()->onMouseClick(button, state, x, y);
}
void motionCallback(int x, int y) {
    RenderEngine::getInstance()->onMouseMove(x, y);
}
void passiveMotionCallback(int x, int y) {
    RenderEngine::getInstance()->onMousePassiveMove(x, y);
}
void createMenu() {
    Menu* menu = new Menu("Main");
    menu->registerMenuCallback(menuCallback);
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
    menu->create();
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
    Window* window = Window::getInstance(1000, 600, 100, 100);
    window->init(argc, argv);
    window->setTitle("Computer Graphics");
    // window->setBackgroundColor(0.9, 0.9, 0.9);
    window->setMouseCursor(GLUT_CURSOR_CROSSHAIR);
    window->configureClippingArea();
    window->registerDisplayCallback(displayCallback);
    window->registerReshapeCallback(reshapeCallback);
    window->registerMouseCallback(mouseCallback);
    window->registerMotionCallback(motionCallback);
    window->registerPassiveMotionCallback(passiveMotionCallback);
    createMenu();
    window->start();
    return 0;
}
