#include <chrono>
#include "Line.h"
#include "Point.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Parabola.h"
#include "Hyperbola.h"

using namespace std;
using namespace std::chrono;
using namespace std::placeholders;

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
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2i(WINDOW_WIDTH/2, 0);
        glVertex2i(WINDOW_WIDTH/2, WINDOW_HEIGHT);
    glEnd();
    glFlush();

    switch (option) {
        case 0: case 1: {
            // draw line
            glColor3f(1.0, 0.0, 0.0);
            Line line(args);

            if (option == 0)  {
                int time = measureTime(bind(&Line::drawByDDA, line)); 
                cout << "Drawing by DDA tooks: " << time << " microseconds" << endl;
            } else {
                int time = measureTime(bind(&Line::drawByBresenham, line));
                cout << "Drawing by Bresenham tooks: " << time << " microseconds" << endl;
            }
            
            args[0] += WINDOW_WIDTH/2;
            args[2] += WINDOW_WIDTH/2;

            glColor3f(0.0, 0.0, 1.0);
            Line lineGL = Line(args);
            int GLTime = measureTime(bind(&Line::drawByGL, lineGL));
            cout <<  "Drawing by OpenGL tooks: " << GLTime << " microseconds" << endl;
            break;
        }
        case 2: {
            // draw circle using Mid-Point
            cout << "Drawing circle using Mid-Point" << endl;
            Circle cirle(args);
            glColor3f(1.0, 0.0, 0.0);
            int time = measureTime(bind(&Circle::drawByMidPoint, cirle));
            cout << "Drawing by Mid-Point tooks: " << time << " microseconds" << endl;

            args[0] += WINDOW_WIDTH/2;

            // draw circle using OpenGL
            glColor3f(0.0, 0.0, 1.0);
            Circle circleGL(args);
            int GLTime = measureTime(bind(&Circle::drawByGL, circleGL));
            cout << "Drawing by OpenGL tooks: " << GLTime << " microseconds" << endl;
            break;
        }
        case 3: {
            // draw ellipse using Mid-Point
            cout << "Drawing ellipse using Mid-Point" << endl;
            Ellipse ellipse(args);
            glColor3f(1.0, 0.0, 0.0);
            int time = measureTime(bind(&Ellipse::drawByMidPoint, ellipse));
            cout << "Drawing by Mid-Point tooks: " << time << " microseconds" << endl;

            args[0] += WINDOW_WIDTH/2;

            // draw ellipse using OpenGL
            glColor3f(0.0, 0.0, 1.0);
            Ellipse ellipseGL(args);
            int GLTime = measureTime(bind(&Ellipse::drawByGL, ellipseGL));
            cout << "Drawing by OpenGL tooks: " << GLTime << " microseconds" << endl;
            break;
        }
        case 4: {
            // draw parabola using Mid-Point
            cout << "Drawing parabola using Mid-Point" << endl;
            Parabola parabola(args);
            glColor3f(1.0, 0.0, 0.0);
            int time = measureTime(bind(&Parabola::drawByMidPoint, parabola));
            cout << "Drawing by Mid-Point tooks: " << time << " microseconds" << endl;
            
            args[0] += WINDOW_WIDTH/2;

            // draw parabola using OpenGL
            glColor3f(0.0, 0.0, 1.0);
            Parabola parabolaGL(args);
            int GLTime = measureTime(bind(&Parabola::drawByGL, parabolaGL));
            cout << "Drawing by OpenGL tooks: " << GLTime << " microseconds" << endl;
            break;
        }
        case 5: {
            // draw hyperbola using Mid-Point
            cout << "Drawing hyperbola using Mid-Point" << endl;
            Hyperbola hyperbola(args);
            glColor3f(1.0, 0.0, 0.0);
            int time = measureTime(bind(&Hyperbola::drawByMidPoint, hyperbola));
            cout << "Drawing by Mid-Point tooks: " << time << " microseconds" << endl;

            args[0] += WINDOW_WIDTH/2;

            // draw hyperbola using OpenGL
            glColor3f(0.0, 0.0, 1.0);
            Hyperbola hyperbolaGL(args);
            int GLTime = measureTime(bind(&Hyperbola::drawByGL, hyperbolaGL));
            cout << "Drawing by OpenGL tooks: " << GLTime << " microseconds" << endl;
            break;
        }
        default:
            break;
    }
}

// void reshape(GLsizei width, GLsizei height) {
//     glClear(GL_COLOR_BUFFER_BIT);
// }

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
    // glutReshapeFunc(reshape);

    // enter the main loop
    glutMainLoop();
    return 0;
}