#include "Menu.h"
#include "RenderEngine.h"

void displayCallback() {
    RenderEngine::getInstance()->render();
    glFlush();
}
void reshapeCallback(GLsizei width, GLsizei height) {
    glClear(GL_COLOR_BUFFER_BIT);
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

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutCreateWindow("My Paint");
    
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glClearColor(0, 0, 0, 1);

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
