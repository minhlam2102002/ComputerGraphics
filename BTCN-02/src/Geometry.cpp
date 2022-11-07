#include "Geometry.h"

Point::Point() { x = y = 0; }
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
void Point::vertex() {
    glVertex2i(x, y);
}

RGBColor::RGBColor() {
    this->r = this->b = this->g = 0;
}
RGBColor::RGBColor(GLfloat r, GLfloat g, GLfloat b) {
    this->r = r;
    this->g = g;
    this->b = b;
}
RGBColor::RGBColor(GLfloat pixel[3]) {
    this->r = pixel[0];
    this->g = pixel[1];
    this->b = pixel[2];
}
void RGBColor::set() {
    glColor3f(r, g, b);
}

Object::Object(Point p, RGBColor c) {
    this->start = this->end = p;
    this->color = c;
}
void Object::update(Point p) {
    this->end = p;
}

Brush::Brush(Point p, RGBColor c) : Object(p, c) {}
void Brush::render() {
    glBegin(GL_POINTS);
    this->color.set();
    this->start.vertex();
    glEnd();
    glFlush();
}

Line::Line(Point p, RGBColor c) : Object(p, c) {}
void Line::render() {
    glBegin(GL_LINES);
    this->color.set();
    this->start.vertex();
    this->end.vertex();
    glEnd();
    glFlush();
}

Rectangle::Rectangle(Point p, RGBColor c) : Object(p, c) {}
void Rectangle::render() {
    glBegin(GL_LINE_LOOP);
    this->color.set();
    glVertex2i(start.x, start.y);
    glVertex2i(start.x, end.y);
    glVertex2i(end.x, end.y);
    glVertex2i(end.x, start.y);
    glEnd();
    glFlush();
}

Square::Square(Point p, RGBColor c) : Object(p, c) {}
void Square::render() {
    // glBegin(GL_LINES);
    // this->color.set();
    
    // glEnd();
    // glFlush();
}