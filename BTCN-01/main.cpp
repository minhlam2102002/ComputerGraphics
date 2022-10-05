#include <chrono>
#include "Line.h"
#include "Point.h"
// #include "Circle.h"
// #include "Ellipse.h"
// #include "Hyperbole.h"
using namespace std;
using namespace std::chrono;
using namespace std::placeholders;

const int WINDOW_WIDTH = 1000, WINDOW_HEIGHT = 500;
const int WINDOW_X = 400, WINDOW_Y = 150;

int option;
vector<int> args;

int measureTime(function<void()> func) {
    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

void parseArguments(int& argc, char** argv) {
    option = stoi(argv[1]);
    for (int i = 2; i < argc; i++) args.push_back(stoi(argv[i]));
    argc = 1;
}

void display() {
    glBegin(GL_LINES);
        glVertex2f(WINDOW_WIDTH/2, 0);
        glVertex2f(WINDOW_WIDTH/2, WINDOW_HEIGHT);
    glEnd();
    switch (option) {
        case 0: {
            // draw line using DDA
            glColor3f(1.0, 0.0, 0.0);
            Line lineDDA = Line(args);
            int DDATime = measureTime(bind(&Line::drawByDDA, lineDDA));
            cout << "Drawing by DDA tooks: " << DDATime << " microseconds" << endl;
            
            args[0] += WINDOW_WIDTH/2;
            args[2] += WINDOW_WIDTH/2;
            glColor3f(0.0, 0.0, 1.0);
            Line lineGL = Line(args);
            int GLTime = measureTime(bind(&Line::drawByGL, lineGL));
            cout <<  "Drawing by OpenGL tooks: " << GLTime << " microseconds" << endl;
            break;
        }
        case 1:
            // draw line using Bresenham
            // Line l2(args);
            // line.drawByBresenham();
            break;
        case 2:
            // draw circle using Mid-Point
            // Circle circle(args);
            break;
        case 3:
            // draw ellipse using Mid-Point
            break;
        case 4:

            break;
        case 5:

            break;
        default:
            break;
    }
}

void reshape(GLsizei width, GLsizei height) {
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
    parseArguments(argc, argv);

    // initialize the window
    glutInit(&argc, nullptr);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_X, WINDOW_Y);

    // create the window
    glutCreateWindow("Computer Graphics");

    // configure the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();           
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);

    // register the callback function
    glutDisplayFunc(display);

    // register reshape callback
    glutReshapeFunc(reshape);

    // enter the main loop
    glutMainLoop();
    return 0;
}