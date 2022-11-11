#pragma once
#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;
using namespace std::chrono;
using namespace std::placeholders;

extern int SCREEN_WIDTH, SCREEN_HEIGHT;

struct RGBColor {
    static const int BYTE_SIZE = 3;
    float r, g, b;
    RGBColor();
    RGBColor(float, float, float);

    friend bool operator==(const RGBColor&, const RGBColor&);
    friend bool operator!=(const RGBColor&, const RGBColor&);
    friend ostream& operator<<(ostream&, const RGBColor&);
};

struct Pixel {
    int x, y;
    Pixel();
    Pixel(int, int);

    vector<Pixel> getNeighbours() const;

    friend Pixel operator+(const Pixel&, const Pixel&);
    friend Pixel operator-(const Pixel&, const Pixel&);
    friend Pixel operator/(const Pixel&, const int&);
    friend ostream& operator<<(ostream&, const Pixel&);
};

int measureTime(void (*)());
void glVertex(const Pixel &);
void glColor(const RGBColor &);

extern vector<RGBColor> colorsMap;
extern vector<string> colorNames;