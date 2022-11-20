#include "Menu.h"
#include "RenderEngine.h"

void createMenu() {
    Menu* menu = new Menu("Main");
    menu->addEntries({"Brush"});
    menu->addEntries({"Line"});
    menu->addSubMenu("Triangle")
        ->addEntries({"Right", "Equilateral", "Isosceles"});
    menu->addSubMenu("Quadrangle")
        ->addEntries({"Rectangle", "Square"});
    menu->addSubMenu("ConicSection")
        ->addEntries({"Circle", "Ellipse"});
    menu->addSubMenu("Polygon")
        ->addEntries({"Pentagon", "Hexagon", "Octagon"});
    menu->addSubMenu("Shape")
        ->addEntries({"Arrow", "Star"});
    menu->addSubMenu("Operator")
        ->addEntries({"Plus", "Minus", "Multiply", "Divide"});
    menu->addSubMenu("Color")
        ->addEntries(colorNames);
    menu->addEntries({"Fill"});
    // menu->addEntries({"Erase"});
    menu->addEntries({"Clear"});
    menu->addEntries({"Exit"});
    menu->create([](int option) {
        RenderEngine::getInstance()->menuCallback(option);
    });
    menu->attachTo(GLUT_RIGHT_BUTTON);
}

int SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 800;

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    SCREEN_WIDTH = glutGet(GLUT_SCREEN_WIDTH) * 0.8;
    SCREEN_HEIGHT = glutGet(GLUT_SCREEN_HEIGHT) * 0.8;

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("My Paint");
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glClearColor(0, 0, 0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    glutDisplayFunc([] {
        RenderEngine::getInstance()->displayCallback();
    });
    glutReshapeFunc([](int width, int height) {
        RenderEngine::getInstance()->reshapeCallback(width, height);
    });
    glutMotionFunc([](int x, int y) {
        RenderEngine::getInstance()->motionCallback(x, y);
    });
    glutMouseFunc([](int button, int state, int x, int y) {
        RenderEngine::getInstance()->mouseCallback(button, state, x, y);
    });

    createMenu();

    glutMainLoop();
    return 0;
}
