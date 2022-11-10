#include "Menu.h"
#include "RenderEngine.h"
#include "Object.h"

void displayCallback() {
    RenderEngine::getInstance()->render();
    glFlush();
}
void reshapeCallback(GLsizei width, GLsizei height) {
    glClear(GL_COLOR_BUFFER_BIT);
    RenderEngine::getInstance()->render();
    glFlush();
}
void menuCallback(int option) {
    cout << "Option " << option << " is chosen." << endl;
    if (option == Entry::idMap["Red"]) {
        RenderEngine::getInstance()->setColor(RGBColor(1, 0, 0));
    } else if (option == Entry::idMap["Green"]) {
        RenderEngine::getInstance()->setColor(RGBColor(0, 1, 0));
    } else if (option == Entry::idMap["Blue"]) {
        RenderEngine::getInstance()->setColor(RGBColor(0, 0, 1));
    } else if (option == Entry::idMap["Yellow"]) {
        RenderEngine::getInstance()->setColor(RGBColor(1, 1, 0));
    } else if (option == Entry::idMap["Cyan"]) {
        RenderEngine::getInstance()->setColor(RGBColor(0, 1, 1));
    } else if (option == Entry::idMap["Magenta"]) {
        RenderEngine::getInstance()->setColor(RGBColor(1, 0, 1));
    } else if (option == Entry::idMap["White"]) {
        RenderEngine::getInstance()->setColor(RGBColor(1, 1, 1));
    } else if (option == Entry::idMap["Black"]) {
        RenderEngine::getInstance()->setColor(RGBColor(0, 0, 0));
    } else if (option == Entry::idMap["Clear"]) {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    } 
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

int SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 800;


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    SCREEN_WIDTH = glutGet(GLUT_SCREEN_WIDTH);
    SCREEN_HEIGHT = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("My Paint");
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glClearColor(0, 0, 0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutMotionFunc(motionCallback);
    glutMouseFunc(mouseCallback);

    createMenu();

    glutMainLoop();
    return 0;
}
